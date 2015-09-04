#ifndef PACHYMETRYVISUALISATION_H
#define PACHYMETRYVISUALISATION_H 

#include "Point.h"
#include "ColorElevationMap.h"
#include "UtilsVectorContour.h"


class PachymetryVisualisation : public ColorElevationMap
{
	public:
		PachymetryVisualisation(std::vector<std::vector<Point> >* posterior, std::vector<std::vector<float> > *anterior, float valeurNull);
		virtual ~PachymetryVisualisation();

	protected:
		void contourBuild(std::vector<std::vector<float> > anterior);
		std::vector< std::vector<float> > contour;

};




#endif