#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "vector"
#include "UtilsFloat.h"



class Point
{
	public:
		Point(float x,float y,float z);
		Point(std::vector<float> coordonate);
		Point(Point* Point);
		Point();
		virtual ~Point();
		float getX();
		float getY();
		float getZ();
		Point* getPoint();
		void setX(float x);
		void setY(float y);
		void setZ(float Z);
		void setCoordonne(float x, float y, float z);
		void setCoordonne(std::vector<float>* coordonate);
		void setCoordonne(std::vector<float> coordonate);
		bool isEqual(Point &pointB);
		bool isNotEqual(Point pointB);
		bool isNull();
		void copy(Point pointB);
		void copy(Point *pointB);
		void print();
		std::string toString();
		int findCoordPointeur(float &xP, float &yP, std::vector<std::vector<float> > * matrice, float valeurNull);
		int findCoord(float xP, float yP, std::vector<std::vector<float> > * matrice, float valeurNull);


	protected:
		float x;
		float y;
		float z;
	private:

	
};



#endif //POINT_H