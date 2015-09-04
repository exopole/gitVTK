#include "Vector.h"

/**
*\fn Vector::Vector():Point()
*\brief constructeur of a null vector
*/
Vector::Vector():Point()
{

}

/**
* \fn Vector(float x, float y, float z):Point(x, y, z)
* \brief constructeur 
* \param coordone in float of x, y, z
*/
Vector::Vector(float x, float y, float z):Point(x, y, z)
{

}

/**
* \fn Vector(Point &origine, Point &arriver)
* \brief constructeur (PointA - pointB) 
* \param 2 points
*/
Vector::Vector(Point origine, Point arriver)
{
	x = arriver.getX() - origine.getX();
	y = arriver.getY() - origine.getY();
	z = arriver.getZ() - origine.getZ();
}

/**
* \fn Vector(float Scalar, Vector &vecteur)
* \brief constructeur (scalar*vecteur) 
* \param scalar float and a vecteur
*
*	 x*scalar, y*scalar, z*scalar
*/
Vector::Vector(float Scalar, Vector *vecteur)
{
	x = Scalar*vecteur->getX();
	y = Scalar*vecteur->getZ();
	z = Scalar*vecteur->getY();
}

/**
* \fn Vector(float &vecteur1, Vector &vecteur2)
* \brief constructeur (vecteur*vecteur) 
* \param 2 vecteurs
*	
* 	Ce vecteur est le vecteur normale entre 2 vecteur en 3 dimension. Il est perpendiculaire a ces vecteurs.
*	n = u * v;
*	n = s1.x + s2.y + s3.z
*	s1 = (u.y*v.z) - (u.z*v.y) 
*	s2 = (u.x*v.z) - (u.z*v.x)
*	s3 = (u.x*v.y) - (u.y*v.x) 
*/
Vector::Vector(Vector *vecteur1 , Vector *vecteur2)
{
	x = vecteur1->getY()*vecteur2->getZ() - vecteur1->getZ()*vecteur2->getY();
	y = vecteur1->getX()*vecteur2->getZ() - vecteur1->getZ()*vecteur2->getX();
	x = vecteur1->getX()*vecteur2->getY() - vecteur1->getY()*vecteur2->getX();
}

// dot product (3D) which allows vector operations in arguments
/**
* \fn Vector(float Scalar, Vector &vecteur)
* \brief constructeur (scalar*vecteur) 
* \param scalar float and a vecteur
*
*	 x*scalar, y*scalar, z*scalar
*/
float Vector::dot(Vector *vect)
{
	return x*vect->getX() + y*vect->getY() + z*vect->getZ();
}

bool Vector::vecteurNull()
{
	return (x == 0 && y == 0 && z == 0) ;
}

