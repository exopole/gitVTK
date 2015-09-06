#ifndef UTILSCONTOUR_H
#define UTILSCONTOUR_H value

#include "UtilsVector.h"
#include "UtilsVectorDirection.h"

class UtilsVectorContour
{
public:
	UtilsVectorContour();
	~UtilsVectorContour();

	///\brief refine the contour by erase arms
    static void eraseArmContour(std::vector<std::vector<float> > *matrice, float valeurNull );
    static void eraseLine(std::vector<std::vector<float> > *matrice, int number, float valeurNull );
    static void fillHoleInMatrice(std::vector<std::vector<float> > *matrice, float valeurNull);
    static void fillSurfaceInMatrice(std::vector<std::vector<float> > *matriceValue, float valeurNull);
    static void bringOutOutsideValue(std::vector<std::vector<float> > *matriceValue, std::vector<std::vector<float> > *matriceTemoin, int x, int y, float valeurNull);
    static void bringOutInsideValue(std::vector<std::vector<float> > *matriceValue, std::vector<std::vector<float> > *matriceTemoin, int x, int y, float valeurNull);
    
    /// count the number of value non null consecutive
    static int numberOfFaces(Point *P1, std::vector<std::vector<float> > *matrice, float valeurNull);

    static std::vector< std::vector<float> > getContour(std::vector<std::vector<float> > *matrice, float valeurIgnore);
    static std::vector< std::vector<float> > getContour(std::vector<std::vector<float> > matrice, float valeurIgnore);
    
    static std::vector< std::vector<Point> > getContour(std::vector<std::vector<Point> > *matrice);
    static std::vector<Point>  getCoordContourFromPoint(std::vector<std::vector<float> >* matrice, Point* begin,float valeurIgnore);

protected:
private:

	
};





#endif