#include "Triangle.h"

/**
* \fn Triangle(float V0, float V1, float V2)
* \brief constructeur of the triangle
* \param 3 float 
*/
Triangle::Triangle(Point* V0, Point* V1, Point* V2)
{
	this->V0 = V0;
	this->V1 = V1;
	this->V2 = V2;
}



/**
* \fn Triangle()
* \brief constructeur of the triangle
*/
Triangle::Triangle()
{

}

/**
* \fn V0()
* \return V0 
*/
Point* Triangle::getV0()
{
	return V0;
}

/**
* \fn V1()
* \return V1
*/
Point* Triangle::getV1()
{
	return V1;
}

/**
* \fn V2()
* \return V2
*/
Point* Triangle::getV2()
{
	return V2;
}


void Triangle::setCoordonne(Point* V0, Point* V1, Point* V2){
	this->V0 = V0;
	this->V1 = V1;
	this->V2 = V2;
}

void Triangle::setAllX(float value, int type){
	if (type == 1)
	{
		V0->setX(V0->getX() + value);
		V1->setX(V1->getX() + value);
		V2->setX(V2->getX() + value);
	}
	else if (type == 2)
	{
		V0->setX(V0->getX() * value);
		V1->setX(V1->getX() * value);
		V2->setX(V2->getX() * value);
	}
	else if (type == 3)
	{
		V0->setX(V0->getX() / value);
		V1->setX(V1->getX() / value);
		V2->setX(V2->getX() / value);
	}

}

void Triangle::setAllX(std::vector<float> * coordX){

	V0->setX(coordX->at(V0->getX()));
	V1->setX(coordX->at(V1->getX()));
	V2->setX(coordX->at(V2->getX()));
}


void Triangle::setAllX(std::vector<float> coordX){

	V0->setX(coordX[V0->getX()]);
	V1->setX(coordX[V1->getX()]);
	V2->setX(coordX[V2->getX()]);
}


void Triangle::setAllY(float value, int type){
	if (type == 1)
	{
		V0->setY(V0->getY() + value);
		V1->setY(V1->getY() + value);
		V2->setY(V2->getY() + value);
	}
	else if (type == 2)
	{
		V0->setY(V0->getY() * value);
		V1->setY(V1->getY() * value);
		V2->setY(V2->getY() * value);
	}
	else if (type == 3)
	{
		V0->setY(V0->getY() / value);
		V1->setY(V1->getY() / value);
		V2->setY(V2->getY() / value);
	}

}

void Triangle::setAllY(std::vector<float> * coordY){

	V0->setY(coordY->at(V0->getY()));
	V1->setY(coordY->at(V1->getY()));
	V2->setY(coordY->at(V2->getY()));
}

void Triangle::setAllY(std::vector<float> coordY){

	V0->setY(coordY[V0->getY()]);
	V1->setY(coordY[V1->getY()]);
	V2->setY(coordY[V2->getY()]);
}

void Triangle::print(){
	std::cout << "V0 : ";
	V0->print();
	std::cout << "V1 : ";
	V1->print();
	std::cout << "V2 : ";
	V2->print();

}


Vec3f Triangle::V0Vec3f(){
	return Vec3f(V0);
}

Vec3f Triangle::V1Vec3f(){
	return Vec3f(V1);
}

Vec3f Triangle::V2Vec3f(){
	return Vec3f(V2);
}


int Triangle::findTriangleFromMatrice( float &xP, float &yP, std::vector<std::vector<float> >*  matrice, float valeurNull)
{
	int V0Find;
	int V1Find;
	int V2Find;
	Point V0;
	Point V1;
	Point V2;

	V0Find = V0.findCoordPointeur(xP, yP, matrice, valeurNull);
	V1Find = V1.findCoord(V0.getX() + 1, V0.getY(), matrice, valeurNull);
	V2Find = V2.findCoord(V0.getX(), V0.getY() + 1, matrice, valeurNull);

	this->setCoordonne(&V0,&V1,&V2);
	
	return V0Find + V1Find + V2Find ;
}

bool Triangle::findTriangleFromMatriceAndV0(Point * V0, std::vector<std::vector<float> >*  matrice, float valeurNull, int type)
{
	int V0Find;
	int V1Find;
	int V2Find;
	Point* V1;
	Point* V2;
	if (type == 1)
	{
		V1Find = V1->findCoord(V0->getX() + 1, V0->getY(), matrice, valeurNull);
		V2Find = V2->findCoord(V0->getX(), V0->getY() + 1, matrice, valeurNull);
	}
	else if(type == 2) {
		V1Find = V1->findCoord(V0->getX() - 1, V0->getY(), matrice, valeurNull);
		V2Find = V2->findCoord( V0->getX(), V0->getY() - 1, matrice, valeurNull);
	}

	else if (type == 3)
	{
		V1Find = V1->findCoord(V0->getX(), V0->getY() + 1, matrice, valeurNull);
		V2Find = V2->findCoord(V0->getX() + 1, V0->getY() + 1, matrice, valeurNull);
	}
	else if (type == 4)
	{
		V1Find = V1->findCoord(V0->getX() + 1, V0->getY(), matrice, valeurNull);
		V2Find = V2->findCoord(V1->getX() , V1->getY() + 1, matrice, valeurNull);
	}

	this->setCoordonne(V0,V1,V2);
	
	return V1Find == 1 && V2Find == 1 ;
}

bool Triangle::containZValue(float value)
{
	return V0->getZ() == value || V1->getZ() == value || V2->getZ() == value;
}


Triangle::~Triangle()
{

}