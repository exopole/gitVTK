#ifndef DATAPACHYMETRY_H
#define DATAPACHYMETRY_H

#include "UtilsVector.h"
#include "UtilsGeometry.h"
#include "Triangle.h"
#include "Utils.h"
#include "ParserTopos.h"



class DataPachymetry
{
 	public:
		DataPachymetry(std::vector<std::vector<float> > *anterior, std::vector<std::vector<float> > *posterior, std::vector<float>* coordXY, 
						 Point* center, float valeurNull); 
		DataPachymetry(ParserTopos* dataTopos, float valeurNull); 
		~DataPachymetry();
		std::vector<std::vector<float> > getAnterior();
		std::vector<std::vector<float> > getPachymetry();
		std::vector<std::vector<Point> > getCoord();
	private:

		void constructCoord(std::vector<std::vector<float> >* anterior, std::vector<std::vector<float> > *posterior,
							float valeurNull);

		void constructCoord(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior,
							float valeurNull);
		void findPointIntersect(Triangle* triangle, float valeurNull, std::vector<std::vector<float> > * matrice);
		void findPointIntersectV2(Triangle* triangle, float valeurNull,  std::vector<std::vector<float> >*  matrice);
		void findPointIntersectV3(Triangle* triangle, 
										float valeurNull,
										std::vector<std::vector<float> >*  matrice);
		Point center;
		std::vector<std::vector<float> > anterior; //vector 2D boolean : true => intersection
		std::vector<std::vector<float> > pachymetry; //vector 2D boolean : true => intersection
		std::vector<std::vector<Point> > coordIntersect; //intersect coordonate anterior(x,y)/posterior(Point)

		std::vector<float> coordXY;
		int nombreIntersect;
};


#endif