#ifndef VECTOR_H
#define VECTOR_H 

#include "Point.h"

class Vector : public Point
{
	public:
		Vector(Point origine, Point arriver);
		Vector(float x, float y, float z);
		Vector(float Scalar, Vector &vecteur);
		Vector(Vector &vec1, Vector &vec2);
		Vector();
		float dot(Vector &vect);
		bool vecteurNull();
	protected:
	private:

};


#endif //VECTOR_H