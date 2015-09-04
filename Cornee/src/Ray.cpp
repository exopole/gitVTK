#include "Ray.h"

/**
* \fn Ray(float P0, float P1)
* \brief constructeur
* \param 2 float origine P0 and direction P1
*/
Ray::Ray(Point P0, Point P1)
{
	this->P0 = &P0;
	this->P1 = &P1;
}

/**
* \fn P0()
* \return Point d'origine
*/
Point* Ray::getP0()
{
	return P0;
}

/**
* \fn P1()
* \return P1 direction
*/
Point* Ray::getP1()
{
	return P1;
}

Ray::~Ray()
{

}
