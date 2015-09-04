

#include "Point.h"
#include "Vector.h"
#include "Ray.h"
#include "Triangle.h"
#include <math.h>

// Copyright 2001 softSurfer, 2012 Dan Sunday
// This code may be freely used, distributed and modified for any purpose
// providing that this copyright notice is included with it.
// SoftSurfer makes no warranty for this code, and cannot be held
// liable for any real or imagined damage resulting from its use.
// Users of this code must verify correctness for their application.
 

// Assume that classes are already given for the objects:
//    Point and Vector with
//        coordinates {float x, y, z;}
//        operators for:
//            == to test  equality
//            != to test  inequality
//            (Vector)0 =  (0,0,0)         (null vector)
//            Point   = Point ± Vector
//            Vector =  Point - Point
//            Vector =  Scalar * Vector    (scalar product)
//            Vector =  Vector * Vector    (cross product)
//    Line and Ray and Segment with defining  points {Point P0, P1;}
//        (a Line is infinite, Rays and  Segments start at P0)
//        (a Ray extends beyond P1, but a  Segment ends at P1)
//    Plane with a point and a normal {Point V0; Vector  n;}
//    Triangle with defining vertices {Point V0, V1, V2;}
//    Polyline and Polygon with n vertices {int n;  Point *V;}
//        (a Polygon has V[n]=V[0])
//===================================================================
 

#define SMALL_NUM   0.00000001 // anything that avoids division overflow

// intersect3D_RayTriangle(): find the 3D intersection of a ray with a triangle
//    Input:  a ray R, and a triangle T
//    Output: *I = intersection point (when it exists)
//    Return: -1 = triangle is degenerate (a segment or point)
//             0 =  disjoint (no intersect)
//             1 =  intersect in unique point I1
//             2 =  are in the same plane


int intersect3D_RayTriangle( Ray R, Triangle T, Point &I )
{
   // Vector    u, v, n;              // triangle vectors
    //Vector    dir, w0, w;           // ray vectors
    float     r, a, b;              // params to calc ray-plane intersect

    // get triangle edge vectors and plane normal
    Vector u(T.V0(), T.V1());
    Vector v(T.V0(), T.V2());
    Vector n(u,v);              // cross product
    if (n.vecteurNull())             // triangle is degenerate
        return -1;                  // do not deal with this case

    Vector dir(R.P1(), R.P0());              // ray direction vector
    Vector w0(R.P0(),T.V0());
    a = - n.dot(w0);
    b = n.dot(dir);
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

    I.setCoordonne(R.P0().x() + r * dir.x(), R.P0().y() + r * dir.y(),R.P0().z() + r * dir.z()); // intersect point of ray and plane

    // is I inside T?
    float    uu, uv, vv, wu, wv, D;
    uu = u.dot(u);
    uv = u.dot(v);
    vv = v.dot(v);
    Vector w(I,T.V0());
    wu = w.dot(u);
    wv = w.dot(v);
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

int main(int argc, char *argv[])
{
	std::cout << "/////////////////////   POINT   //////////////////////////////////" << std::endl;
    Point newPoint(0,1,2);
    std::cout << "x : " << newPoint.x() << std::endl;
    std::cout << "y : " << newPoint.y() << std::endl;
    std::cout << "z : " << newPoint.z() << std::endl;
    newPoint.setY(5);
    Point pointB;
    std::cout << "y : " << pointB.y() << std::endl;

    if (! newPoint.isNotEqual(pointB))
    	std::cout << "equal" << std::endl;
    else
    	std::cout << "nonEqual" << std::endl;

	std::cout << "/////////////////////   VECTOR   //////////////////////////////////" << std::endl;

	Vector newVector, vect;
    newVector.setCoordonne(-8.0, 5.0, 6.0);
    Vector vec2(newPoint, pointB);
    Vector vec3(newVector, vec2);
    std::cout << "x2 : " << vec2.x() << std::endl;
    std::cout << "y2 : " << vec2.y() << std::endl;
    std::cout << "z2 : " << vec2.z() << std::endl;

    if (vect.vecteurNull())
    	std::cout << "vec Null" << std::endl;
    else
    	std::cout << "vec Non NUll" << std::endl;

    if (newVector.vecteurNull())
    	std::cout << "newVector Null" << std::endl;
    else
    	std::cout << "newVector Non NUll" << std::endl;

    std::cout << "dot => " << newVector.dot(vec2) << std::endl; 

    std::cout << "x3 : " << vec3.x() << std::endl;
    std::cout << "y3 : " << vec3.y() << std::endl;
    std::cout << "z3 : " << vec3.z() << std::endl;

	std::cout << "/////////////////////   RAY   //////////////////////////////////" << std::endl;

	Ray newRay(pointB,newPoint);
	std::cout << "origine : " << newRay.P0().x() << ", " << newRay.P0().y() << ", " << newRay.P0().z()<< std::endl;
	std::cout << "direction : " << newRay.P1().x() << ", " << newRay.P1().y() << ", " << newRay.P1().z() << std::endl;

	std::cout << "/////////////////////   Triangle   //////////////////////////////////" << std::endl;

	Point pointC(6,8,5);
    Point V2(0,-1,-10);
    Point V0(5,-50,59);
    Point V1(9,0,-25);
	Triangle newTriangle(V0,V1,V2);
	std::cout << "coordonnee : " << newTriangle.V0().x() << ", " << newTriangle.V1().y() << ", "<< newTriangle.V2().z() << std::endl; 

	std::cout << "/////////////////////   Point/Triangle   //////////////////////////////////" << std::endl;
	Point I;
	std::cout << newRay.P0().x() + 6 * newVector.x() << std::endl;
	std::cout << newRay.P0().y() + 6 * newVector.y() << std::endl;
	std::cout << newRay.P0().z() + 6 * newVector.z() << std::endl;
	I.setCoordonne(newRay.P0().x() + 6 * newVector.x(), newRay.P0().y() + 6 * newVector.y(), newRay.P0().z() + 6 * newVector.z());	
	std::cout << "coucou" << std::endl;

	std::cout << "/////////////////////  test intersect   //////////////////////////////////" << std::endl;

	int test;
	test = intersect3D_RayTriangle(newRay, newTriangle, I);
	std::cout << "I : " << I.x() << ", " << I.y() <<", "<< I.z() << "\n test : " << test << std::endl; 


	std::cout << "/////////////////////   VECTOR/Triangle  //////////////////////////////////" << std::endl;

	Vector newVector2(newTriangle.V0(), newTriangle.V1());

    std::cout << "x : " << newVector2.x() << std::endl;
    std::cout << "y : " << newVector2.y() << std::endl;
    std::cout << "z : " << newVector2.z() << std::endl;

    return 0;
}
