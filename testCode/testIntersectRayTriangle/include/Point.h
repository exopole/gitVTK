#ifndef POINT_H
#define POINT_H

#include <iostream>



class Point
{
	public:
		Point(float x,float y,float z);
		Point();
		virtual ~Point();
		float x();
		float y();
		float z();
		Point getPoint();
		void setX(float x);
		void setY(float y);
		void setZ(float Z);
		void setCoordonne(float x, float y, float z);
		bool isEqual(Point &pointB);
		bool isNotEqual(Point pointB);
		void copy(Point pointB);
	protected:
		float m_x;
		float m_y;
		float m_z;
	private:

	
};



#endif //POINT_H