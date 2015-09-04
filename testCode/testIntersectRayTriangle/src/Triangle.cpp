#include "Triangle.h"

/**
* \fn Triangle(float V0, float V1, float V2)
* \brief constructeur of the triangle
* \param 3 float 
*/
Triangle::Triangle(Point V0, Point V1, Point V2)
{
	m_V0 = V0;
	m_V1 = V1;
	m_V2 = V2;
}

/**
* \fn V0()
* \return m_V0 
*/
Point Triangle::V0()
{
	return m_V0;
}

/**
* \fn V1()
* \return m_V1
*/
Point Triangle::V1()
{
	return m_V1;
}

/**
* \fn V2()
* \return m_V2
*/
Point Triangle::V2()
{
	return m_V2;
}

Triangle::~Triangle()
{

}