#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle
{
	public:
		Triangle(Point V0, Point V1, Point V2);
		~Triangle();
		Point V0();
		Point V1();
		Point V2();
	private:
		Point m_V0;
		Point m_V1;
		Point m_V2;
};

#endif //TRIANGLE