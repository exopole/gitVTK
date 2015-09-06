#include "Point.h"

Point::Point(float x,float y,float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


Point::Point(std::vector<float> coordonate)
{
	this->x = coordonate[0];
	this->y = coordonate[1];
	this->z = coordonate[2];	
}

Point::Point(Point* point)
{
	this->x = point->getX() ;
	this->y = point->getY() ;
	this->z = point->getZ() ;	
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}


float Point::getX()
{
	return this->x;
}

float Point::getY()
{
	return y;
}

float Point::getZ()
{
	return z;
}

Point* Point::getPoint()
{
	return this;
}

void Point::setX(float x)
{
	this->x = x;
}

void Point::setY(float y)
{
	this->y = y;
}

void Point::setZ(float z)
{
	this->z = z;
}

void Point::setCoordonne(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::setCoordonne(std::vector<float>* coordonate)
{
	x = coordonate->at(0);
	y = coordonate->at(1);
	z = coordonate->at(2);	
}

void Point::setCoordonne(std::vector<float> coordonate)
{
	x = coordonate[0];
	y = coordonate[1];
	z = coordonate[2];	
}

bool Point::isEqual(Point &pointB)
{
	return pointB.getX() == this->getX() && pointB.getY() == this->getY() && pointB.getZ() == this->getZ();
}

bool Point::isNotEqual(Point pointB)
{
	return !(this->isEqual(pointB));
}

bool Point::isNull()
{
	return this->x == 0 && this->y == 0 && this->z == 0;
}


void Point::copy(Point pointB)
{
	x = pointB.getX();
	y = pointB.getY();
	z = pointB.getZ();
}

void Point::copy(Point *pointB)
{
	x = pointB->getX();
	y = pointB->getY();
	z = pointB->getZ();
}

void Point::print(){
	std::cout << '[' << x << ' ' << y << ' ' << z << ']' << std::endl;

}


int Point::findCoordPointeur(float &xP, float &yP, std::vector<std::vector<float> > * matrice, float valeurNull)
{
	int trouver(0);
	while (xP < matrice->size()-1 && ! trouver)
	{
		while(yP < matrice->at(xP).size()-1 && ! trouver)
		{
			if (matrice->at(xP)[yP] != valeurNull)
			{
				this->setCoordonne(xP, yP, matrice->at(xP)[yP]);
				trouver = 1;

			}
			yP++;
		}

		if(!trouver && yP == matrice->at(xP).size()-1) {
			xP++;
			yP = 0;
		}
	}
	return trouver;
}

int Point::findCoord(float xP, float yP, std::vector<std::vector<float> >* matrice, float valeurNull)
{
	int trouver(0);
	while (xP < matrice->size() && ! trouver)
	{
		while(yP < matrice->at(xP).size() && ! trouver)
		{
			if (matrice->at(xP)[yP] != valeurNull)
			{
				this->setCoordonne(xP, yP, matrice->at(xP)[yP]);
				trouver = 1;
			}
			yP++;
		}
		yP = 0;
		xP++;
	}
	return trouver;
}


std::string Point::toString(){
	std::string coucou = UtilsFloat::float2string(x) ;
	return "[" + UtilsFloat::float2string(x) + "," + UtilsFloat::float2string(y) + "," + UtilsFloat::float2string(z) + "]" ;
}


Point::~Point()
{

}

