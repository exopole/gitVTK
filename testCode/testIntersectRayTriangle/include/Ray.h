#ifndef RAY_H
#define RAY_H 

#include "Point.h"

class Ray
{
	public:
		Ray(Point P0, Point P1);
		~Ray();
		Point P0();
		Point P1();
	private:
		Point m_P0;
		Point m_P1;
};

#endif //RAY_H