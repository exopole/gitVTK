#ifndef RAY_H
#define RAY_H 

#include "Point.h"

class Ray
{
	public:
		Ray(Point P0, Point P1);
		~Ray();
		Point* getP0();
		Point* getP1();
	private:
		Point* P0;
		Point* P1;
};

#endif //RAY_H