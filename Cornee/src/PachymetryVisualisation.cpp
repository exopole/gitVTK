#include "PachymetryVisualisation.h"



PachymetryVisualisation::PachymetryVisualisation(std::vector<std::vector<Point> >* posteriorIntersect, 
	std::vector<std::vector<float> >* anterior, float valeurNull )
{
	m_Null = valeurNull;
	UtilsVector::printVector(anterior, m_Null);
	contour = UtilsVectorContour::getContour(anterior, m_Null);
	std::cout << "contour" << std::endl;

	UtilsVector::printVector(contour, m_Null);
}



PachymetryVisualisation::~PachymetryVisualisation()
{
    //dtor
}
