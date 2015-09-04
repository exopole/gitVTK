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
	m_x = arriver.x() - origine.x();
	m_y = arriver.y() - origine.y();
	m_z = arriver.z() - origine.z();
}

/**
* \fn Vector(float Scalar, Vector &vecteur)
* \brief constructeur (scalar*vecteur) 
* \param scalar float and a vecteur
*
*	 x*scalar, y*scalar, z*scalar
*/
Vector::Vector(float Scalar, Vector &vecteur)
{
	m_x = Scalar*vecteur.x();
	m_y = Scalar*vecteur.z();
	m_z = Scalar*vecteur.y();
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
Vector::Vector(Vector &vecteur1 , Vector &vecteur2)
{
	m_x = vecteur1.y()*vecteur2.z() - vecteur1.z()*vecteur2.y();
	m_y = vecteur1.x()*vecteur2.z()- vecteur1.z()*vecteur2.x();
	m_x = vecteur1.x()*vecteur2.y() - vecteur1.y()*vecteur2.x();
}

// dot product (3D) which allows vector operations in arguments
/**
* \fn Vector(float Scalar, Vector &vecteur)
* \brief constructeur (scalar*vecteur) 
* \param scalar float and a vecteur
*
*	 x*scalar, y*scalar, z*scalar
*/
float Vector::dot(Vector &vect)
{
	return this->x()*vect.x() + this->y()*vect.y() + this->z()*vect.z();
}

bool Vector::vecteurNull()
{
	return (this->x() == 0 && this->y() == 0 && this->z() == 0) ;
}

