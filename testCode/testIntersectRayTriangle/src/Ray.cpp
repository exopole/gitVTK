#include "Ray.h"

/**
* \fn Ray(float P0, float P1)
* \brief constructeur
* \param 2 float origine P0 and direction P1
*/
Ray::Ray(Point P0, Point P1)
{
	m_P0 = P0;
	m_P1 = P1;
}

/**
* \fn P0()
* \return Point d'origine
*/
Point Ray::P0()
{
	return m_P0;
}

/**
* \fn P1()
* \return P1 direction
*/
Point Ray::P1()
{
	return m_P1;
}

Ray::~Ray()
{

}
