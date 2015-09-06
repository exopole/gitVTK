#ifndef VOLUMEVISUALISATION_H
#define VOLUMEVISUALISATION_H

#include "ColorElevationMap.h"
#include "UtilsVectorContour.h"
#include "Utils.h"
#include "UtilsGeometry.h"

const float indexNull = -2;

class VolumeVisualisation : public ColorElevationMap
{
public:
	VolumeVisualisation(std::vector<std::vector<float> > matriceAnt, std::vector<std::vector<float> > matricePost,  float valeurIgnore);
	~VolumeVisualisation();
private:
	std::vector<std::vector<float> > getContour(std::vector<std::vector<float> > *matrice);
	void mapWithMatrice();
	void newCoord(std::vector<std::vector<float> >* matrice);
	void newIndex(std::vector<std::vector<float> >* matrice, 
									std::vector<std::vector<float> >* matriceIndex, float &index);
	void newScalar(std::vector<std::vector<float> >* matrice, float &index);
	void newCells();
	void newCellsVolume(std::vector<Point >* matrice1, std::vector<Point >* matrice2);
	void createMapper();
	bool pointInFace(std::vector< float > begin, std::vector< float > end, std::vector< float > point);
	bool sameSens(std::vector<Point >* matrice1, std::vector<Point >* matrice2);

	Point findNextPoint(Point* point, std::vector<std::vector<float> > *matrice, 
										int &direction, float valeurNull);
	std::vector<std::vector<float> > anteriorContour;
	std::vector<std::vector<float> > matTest;
	std::vector<std::vector<float> > posteriorContour;
	std::vector<std::vector<float> > anteriorIndex;
	std::vector<std::vector<float> > posteriorIndex;
	std::vector <Point> pointsConfluence;
	int nbrFA;
	int nbrFP;
};

#endif // VOLUMEVISUALISATION_H
