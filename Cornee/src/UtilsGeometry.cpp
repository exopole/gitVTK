#include "UtilsGeometry.h"

// intersect3D_RayTriangle(): find the 3D intersection of a ray with a triangle
//    Input:  a ray R, and a triangle T
//    Output: *I = intersection point (when it exists)
//    Return: -1 = triangle is degenerate (a segment or point)
//             0 =  disjoint (no intersect)
//             1 =  intersect in unique point I1
//             2 =  are in the same plane


int UtilsGeometry::intersect3D_RayTriangle( Ray R, Triangle T, Point *I )
{
   // Vector    u, v, n;              // triangle vectors
    //Vector    dir, w0, w;           // ray vectors
    float     r, a, b;              // params to calc ray-plane intersect

    // get triangle edge vectors and plane normal
    Vec3f u(T.getV0(), T.getV1());
    Vec3f v(T.getV0(), T.getV2());
    Vec3f n;              
    n = u.crossProduct(v);           // cross product
    if (n.vecteurNull())             // triangle is degenerate
        return -1;                  // do not deal with this case

    Vec3f dir(R.getP0(), R.getP1());              // ray direction vector
    Vec3f w0(R.getP0(),T.getV0());
    a = - n.dotProduct(w0);
    b = n.dotProduct(dir);
    if (fabs(b) < SMALL_NUM) {     // ray is  parallel to triangle plane
        if (a == 0)                 // ray lies in triangle plane
            return 2;
        else return 0;              // ray disjoint from plane
    }

    // get intersect point of ray with triangle plane
    r = a / b;
    if (r < 0.0)                    // ray goes away from triangle
        return 0;                   // => no intersect
    // for a segment, also test if (r > 1.0) => no intersect

    I->setCoordonne(R.getP0()->getX() + r * dir.x, R.getP0()->getY() + r * dir.y, R.getP0()->getZ() + r * dir.z); // intersect point of ray and plane

    // is I inside T?
    float    uu, uv, vv, wu, wv, D;
    uu = u.dotProduct(u);
    uv = u.dotProduct(v);
    vv = v.dotProduct(v);
    Vec3f w(I,T.getV0());
    wu = w.dotProduct(u);
    wv = w.dotProduct(v);
    D = uv * uv - uu * vv;

    // get and test parametric coords
    float s, t;
    s = (uv * wv - vv * wu) / D;
    if (s < 0.0 || s > 1.0)         // I is outside T
        return 0;
    t = (uv * wu - uu * wv) / D;
    if (t < 0.0 || (s + t) > 1.0)  // I is outside T
        return 0;

    return 1;                       // I is in T
}

// [comment]
// The main ray-triangle intersection routine. You can test both methoods: the
// geometric method and the Moller-Trumbore algorithm (use the flag -DMOLLER_TRUMBORE
// when you compile.
// [/comment]
bool UtilsGeometry::rayTriangleIntersect(
    const Vec3f &orig, const Vec3f &dir,
    const Vec3f &v0, const Vec3f &v1, const Vec3f &v2,
    float &t, float &u, float &v)
{
#ifdef MOLLER_TRUMBORE
    Vec3f v0v1 = v1 - v0;
    Vec3f v0v2 = v2 - v0;
    Vec3f pvec = dir.crossProduct(v0v2);
    float det = v0v1.dotProduct(pvec);
#ifdef CULLING
    // if the determinant is negative the triangle is backfacing
    // if the determinant is close to 0, the ray misses the triangle
    if (det < kEpsilon) return false;
#else
    // ray and triangle are parallel if det is close to 0
    if (fabs(det) < kEpsilon) return false;
#endif
    float invDet = 1 / det;

    Vec3f tvec = orig - v0;
    u = tvec.dotProduct(pvec) * invDet;
    if (u < 0 || u > 1) return false;

    Vec3f qvec = tvec.crossProduct(v0v1);
    v = dir.dotProduct(qvec) * invDet;
    if (v < 0 || u + v > 1) return false;
    
    t = v0v2.dotProduct(qvec) * invDet;
    
    return true;
#else
    // compute plane's normal
    Vec3f v0v1 = v1 - v0;
    Vec3f v0v2 = v2 - v0;
    // no need to normalize
    Vec3f N = v0v1.crossProduct(v0v2); // N
    float denom = N.dotProduct(N);
    
    // Step 1: finding P
    
    // check if ray and plane are parallel ?
    float NdotRayDirection = N.dotProduct(dir);
    if (fabs(NdotRayDirection) < kEpsilon) // almost 0
        return false; // they are parallel so they don't intersect ! 

    // compute d parameter using equation 2
    float d = N.dotProduct(v0);
    
    // compute t (equation 3)
    t = (N.dotProduct(orig) + d) / NdotRayDirection;
    // check if the triangle is in behind the ray
    if (t < 0) return false; // the triangle is behind
 
    // compute the intersection point using equation 1
    Vec3f P = orig + t * dir;
 
    // Step 2: inside-outside test
    Vec3f C; // vector perpendicular to triangle's plane
 
    // edge 0
    Vec3f edge0 = v1 - v0; 
    Vec3f vp0 = P - v0;
    C = edge0.crossProduct(vp0);
    if (N.dotProduct(C) < 0) return false; // P is on the right side
 
    // edge 1
    Vec3f edge1 = v2 - v1; 
    Vec3f vp1 = P - v1;
    C = edge1.crossProduct(vp1);
    if ((u = N.dotProduct(C)) < 0)  return false; // P is on the right side
 
    // edge 2
    Vec3f edge2 = v0 - v2; 
    Vec3f vp2 = P - v2;
    C = edge2.crossProduct(vp2);
    if ((v = N.dotProduct(C)) < 0) return false; // P is on the right side;

    u /= denom;
    v /= denom;

    return true; // this ray hits the triangle
#endif
}


int UtilsGeometry::intersect_triangle(double orig[3], double dir[3],
                   double vert0[3], double vert1[3], double vert2[3],
                   double *t, double *u, double *v)
{
/*
  std::cout << "vert0 : "<< vert0[0] << ", " <<vert0[1] << ", " << vert0[2] << std::endl;
  std::cout <<"vert1 : "<<  vert1[0] << ", " <<vert1[1] << ", " << vert1[2] << std::endl;
  std::cout <<"vert2 : "<<  vert2[0] << ", " <<vert2[1] << ", " << vert2[2] << std::endl;
  std::cout << "orig : "<< orig[0] << ", " <<orig[1] << ", " << orig[2] << std::endl;
  std::cout << "dir : "<< dir[0] << ", " <<dir[1] << ", " << dir[2] << std::endl;
*/
   double edge1[3], edge2[3], tvec[3], pvec[3], qvec[3];
   double det, inv_det;

   /* find vectors for two edges sharing vert0 */
   SUB(edge1, vert1, vert0);
   SUB(edge2, vert2, vert0);

   /* begin calculating determinant - also used to calculate U parameter */
   CROSS(pvec, dir, edge2);

   /* if determinant is near zero, ray lies in plane of triangle */
   det = DOT(edge1, pvec);

   if (det > -EPSILON && det < EPSILON)
     return 0;
   inv_det = 1.0 / det;

   /* calculate distance from vert0 to ray origin */
   SUB(tvec, orig, vert0);

   /* calculate U parameter and test bounds */
   *u = DOT(tvec, pvec) * inv_det;
   if (*u < 0.0 || *u > 1.0)
     return 0;

   /* prepare to test V parameter */
   CROSS(qvec, tvec, edge1);

   /* calculate V parameter and test bounds */
   *v = DOT(dir, qvec) * inv_det;
   if (*v < 0.0 || *u + *v > 1.0)
     return 0;

   /* calculate t, ray intersects triangle */
   *t = DOT(edge2, qvec) * inv_det;

   return 1;
}


/**
*\fn float UtilsGeometry::distanceBetween3DPoint(Point* P1, Point* P2)
*\brief retourne la distance entre deux points
*\param 2 points
*\return float
*/
float UtilsGeometry::distanceBetween3DPoint(Point* P1, Point* P2){
  return sqrt( pow( P2->getX()-P1->getX(), 2 ) + pow( P2->getY()-P1->getY(), 2 ) + pow( P2->getZ()-P1->getZ(), 2 ));
}

/**
*\fn float UtilsGeometry::distanceBetween3DPoint(Point* P1, Point* P2)
*\brief retourne la distance entre deux points
*\param 2 points
*\return float
*/
float UtilsGeometry::distanceBetween3DPoint(float x1, float y1, float z1, float x2, float y2, float z2){
  return sqrt( pow( x2-x1, 2 ) + pow( y2-y1, 2 ) + pow( z2-z1, 2 ));
}


