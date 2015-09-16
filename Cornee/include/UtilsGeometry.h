#ifndef UTILSGEOMETRY_H
#define UTILSGEOMETRY_H

#define SMALL_NUM   0.00000001
#define kEpsilon 	1e-8


// define pour la fonction intersect_triangle
#define EPSILON 0.000001
#define CROSS(dest,v1,v2) ; dest[0]=v1[1]*v2[2]-v1[2]*v2[1]; dest[1]=v1[2]*v2[0]-v1[0]*v2[2]; dest[2]=v1[0]*v2[1]-v1[1]*v2[0];
#define DOT(v1,v2) (v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2])
#define SUB(dest,v1,v2) dest[0]=v1[0]-v2[0]; dest[1]=v1[1]-v2[1]; dest[2]=v1[2]-v2[2];
#define ADD(dest,v1,v2) dest[0]=v1[0]+v2[0]; dest[1]=v1[1]+v2[1]; dest[2]=v1[2]+v2[2];

#include "Point.h"
#include "Vector.h"
#include "Ray.h"
#include "Triangle.h"
#include <math.h>
#include "Vecteur3D.h"


//float kEpsilon = 1e-8;

inline
float deg2rad(const float &deg)
{ return deg * M_PI / 180; }

inline
float clamp(const float &lo, const float &hi, const float &v)
{ return std::max(lo, std::min(hi, v)); }



class UtilsGeometry
{
 	public:
 		static int intersect3D_RayTriangle( Ray R, Triangle T, Point *I );
	 	static bool rayTriangleIntersect(
							    const Vec3f &orig, const Vec3f &dir,
							    const Vec3f &v0, const Vec3f &v1, const Vec3f &v2,
							    float &t, float &u, float &v
							    );
	 	static int intersect_triangle(double orig[3], double dir[3],
                   double vert0[3], double vert1[3], double vert2[3],
                   double *t, double *u, double *v);
	 	static float distanceBetween3DPoint(Point* P1, Point* P2);
	 	static float distanceBetween3DPoint(float x1, float y1, float z1, float x2, float y2, float z2);
};

#endif