#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Vecteur3D.h"

class Triangle
{
	public:
		Triangle(Point* V0, Point* V1, Point* V2);
		Triangle();
		~Triangle();
		void setCoordonne(Point* V0, Point* V1, Point* v2);
		void setAllX(float value, int type);
		void setAllX(std::vector<float> * coordX);
		void setAllY(float value, int type);
		void setAllY(std::vector<float> * coordY);
		void print();
		Point* getV0();
		Point* getV1();
		Point* getV2();
		Vec3f V0Vec3f();
		Vec3f V1Vec3f();
		Vec3f V2Vec3f();
		int findTriangleFromMatrice( float &xP, float &yP, std::vector<std::vector<float> > * matrice, float valeurNull);
		bool findTriangleFromMatriceAndV0( Point* V0, std::vector<std::vector<float> > * matrice, float valeurNull, int type);
	private:
		Point* V0;
		Point* V1;
		Point* V2;
};

#endif //TRIANGLE