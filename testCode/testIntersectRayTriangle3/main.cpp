#include "Vecteur3D.h"
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>


int main(int argc, char *argv[])
{
	//typedef Vecteur3D<float> Vec3f;
	Vec3f newvect1;
	std::cout << newvect1 << std::endl;
	Vecteur3D<double> newvect(2.5);
	std::cout << newvect << std::endl;
	Vecteur3D<float> newvect3(1.5,2.5,3.50);
	std::cout << newvect3 << std::endl;
	std::cout << IntersectRay::kEpsilon << std::endl;
	return 0;
}