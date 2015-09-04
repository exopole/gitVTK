#include "Point.h"

Point::Point(float x,float y,float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

Point::Point()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}


float Point::x()
{
	return m_x;
}

float Point::y()
{
	return m_y;
}

float Point::z()
{
	return m_z;
}

Point Point::getPoint()
{
	return *this;
}

void Point::setX(float x)
{
	m_x = x;
}

void Point::setY(float y)
{
	m_y = y;
}

void Point::setZ(float z)
{
	m_z = z;
}

void Point::setCoordonne(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

bool Point::isEqual(Point &pointB)
{
	return pointB.x() == this->x() && pointB.y() == this->y() && pointB.z() == this->z();
}

bool Point::isNotEqual(Point pointB)
{
	return !(this->isEqual(pointB));
}


void Point::copy(Point pointB)
{
	m_x = pointB.x();
	m_y = pointB.y();
	m_z = pointB.z();
}

Point::~Point()
{

}

