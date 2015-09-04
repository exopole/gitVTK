#include "VolumeVisualisation.h"

/**
*\fn VolumeVisualisation::VolumeVisualisation(std::vector<std::vector<float> > matriceAnt, 
										std::vector<std::vector<float> > matricePost,  float valeurIgnore)
*\brief Constructeur 
*\param 2 2D vector float (anterior surface, posterior surface)
*\param valeurIgnore
*/
VolumeVisualisation::VolumeVisualisation(std::vector<std::vector<float> > matriceAnt, 
										std::vector<std::vector<float> > matricePost,  float valeurIgnore){
	m_Null = valeurIgnore;
	UtilsVector::initVector(&matTest, 0, matriceAnt.size() );
	anteriorContour = VolumeVisualisation::getContour(&matriceAnt);
	posteriorContour = VolumeVisualisation::getContour(&matricePost);
	UtilsVector::printVector(&anteriorContour, m_Null);
	std::cout << "/////////////////" << std::endl;
	UtilsVector::printVector(&posteriorContour, m_Null);
	
	pointsConfluence = UtilsVector::findPointWithLessDistance(&anteriorContour, &posteriorContour, m_Null);
	nbrFA = UtilsVectorContour::numberOfFaces(&pointsConfluence[0], &anteriorContour,m_Null );
	nbrFP = UtilsVectorContour::numberOfFaces(&pointsConfluence[1], &posteriorContour, m_Null );
	Utils::simplificationFraction(nbrFA , nbrFP);
	ColorElevationMap::newMap(); // attribute initialization
	VolumeVisualisation::mapWithMatrice();
	ColorElevationMap::createMapper();
    m_actor->SetMapper(m_mapper);
    


}


/*!
*\fn void VolumeVisualisation::mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief visualize a map from a matrice f vector
*\param vector of float vector
*\param the value which replace null
*/
void VolumeVisualisation::mapWithMatrice()
{

	    // peut être inutile ... a voir
    m_minScal  = -UtilsVector::getMax(&anteriorContour, m_Null)*10;
    m_maxScal = -UtilsVector::getMin(&posteriorContour, m_Null)*10;
	float index(0);
    VolumeVisualisation::newCoord(&anteriorContour);
    VolumeVisualisation::newCoord(&posteriorContour);

    VolumeVisualisation::newScalar(&anteriorContour, index);
    VolumeVisualisation::newScalar(&posteriorContour, index);

    index = 0;
    VolumeVisualisation::newIndex(&anteriorContour, &anteriorIndex, index);
    VolumeVisualisation::newIndex(&posteriorContour, &posteriorIndex, index);

    VolumeVisualisation::newCells();
    // We now assign the pieces to the vtkPolyData.
    m_polyData->SetPoints(m_points);
    m_polyData->SetPolys(m_polys);
    m_polyData->GetPointData()->SetScalars(m_scalars);
}


/*!
*\fn void VolumeVisualisation::newCoord(std::vector<std::vector<float> > matrice,float valeurIgnore)
*\brief insert all the point from the matrice in the vtkPoint
*\param matrice : vector of float vector
*\param the value that replace the null
*/
void VolumeVisualisation::newCoord(std::vector<std::vector<float> >* matrice)
{

	for (float x = 0; x <  matrice->size(); x++)
		for(float y = 0; y < matrice->at(x).size(); y++)
		{
			float z = matrice->at(x)[y];
			if (z != m_Null)
			{
			    float coord[3]= {x, y, z*10};
			    m_points->InsertPoint(m_nombrePoint++,coord);
			}

	}
}


/*!
*\fn std::vector<std::vector<float> > VolumeVisualisation::newIndex(std::vector<std::vector<float> > matrice,float valeurIgnore)
*\brief creat a vector of float vector that contain all the index
*\param matrice : vector of float vector
*\param the value that replace the null
*\return a matrice of index which describe the place of each coordonnate in the list
*/
void VolumeVisualisation::newIndex(std::vector<std::vector<float> >* matrice, 
									std::vector<std::vector<float> >* matriceIndex, float &index)
{
  std::vector<float> matriceTmp;
  for (int x = 0; x <  matrice->size(); x++)
  {
     for(int y = 0; y < matrice->at(x).size(); y++)
        if (matrice->at(x)[y]==m_Null)
          matriceTmp.push_back(indexNull);
        else
          matriceTmp.push_back(index++);

    matriceIndex->push_back(matriceTmp);

     matriceTmp.clear();
  }

}


/*!
* \fn void SurfaceElevationFromMatrice::newScalar(std::vector<std::vector<float> > matrice, float valeurIgnore)
* \brief add scalar value from a matrice
* \param matrice of float value
* \param the value which replace the null value
*/
void VolumeVisualisation::newScalar(std::vector<std::vector<float> >* matrice, float &index)
{
    float matSize = (float) matrice->size();
    for (float x = 0; x <  matSize; x++)
        for(float y = 0; y < matSize; y++)
        {
            float z = matrice->at(x)[y];
            if (z != m_Null)
            {
                m_scalars->InsertTuple1(index++,-z*10);
            }
        }
}


/*!
*\fn void ColorElevationMap::newCells(std::vector<std::vector<float> > matriceIndex)
*\brief create new cells for the mesh
*\param matrice of index where -1 => value null
*/
void VolumeVisualisation::newCells()
{

	if (nbrFA > nbrFP)
	{
		VolumeVisualisation::newCellsVolume(&anteriorIndex,&pointsConfluence[0], &posteriorIndex, &pointsConfluence[1]);
	}
	else if (nbrFA < nbrFP)
	{
		VolumeVisualisation::newCellsVolume(&posteriorIndex, &pointsConfluence[1], &anteriorIndex,&pointsConfluence[0]);
	}
	else 
	{
		VolumeVisualisation::newCellsVolume(&posteriorIndex, &pointsConfluence[1], &anteriorIndex,&pointsConfluence[0]);
	}
}

/*!
*\fn void ColorElevationMap::newCells(std::vector<std::vector<float> > matriceIndex)
*\brief create new cells for the mesh
*\param matrice of index where -1 => value null
*/
void VolumeVisualisation::newCellsVolume(std::vector<std::vector<float> >* matrice1, Point* beginMat1, 
									std::vector<std::vector<float> >* matrice2, Point* beginMat2)
{

	std::vector<Point> extremFacesMat1, extremFacesMat2;
	int count(0), countMat2(0), i;
	extremFacesMat1 = VolumeVisualisation::buildVectorOfExtremtyFace(beginMat1, matrice1);
	extremFacesMat2 = VolumeVisualisation::buildVectorOfExtremtyFace(beginMat2, matrice2);

	int nbrFMatrice1 = extremFacesMat1.size();
	int nbrFMatrice2 = extremFacesMat2.size();
	Utils::simplificationFraction(nbrFMatrice1 , nbrFMatrice2);
	std::cout << "coucou2 : " << extremFacesMat1.size() << std::endl;
	std::cout << "coucou2 : " << extremFacesMat2.size() << std::endl;
	std::cout << "simplification " << nbrFMatrice1 << ", " << nbrFMatrice2 << std::endl;
	UtilsVector::printVector(&extremFacesMat1);
	std::cout << " ////////////////::" << std::endl;
	UtilsVector::printVector(&extremFacesMat2);
	for (i = 0; i < extremFacesMat1.size()-1; i++)
	{
		std::cout << "countMat2 : " << countMat2 << std::endl;
		ColorElevationMap::addTriangle(matrice1->at(extremFacesMat1[i].getX())[extremFacesMat1[i].getY()],
										matrice1->at(extremFacesMat1[i+1].getX())[extremFacesMat1[i+1].getY()],
										matrice2->at(extremFacesMat2[countMat2].getX())[extremFacesMat2[countMat2].getY()]);
		if (count < nbrFMatrice2 && countMat2 < extremFacesMat2.size()-1)
		{
			ColorElevationMap::addTriangle(matrice2->at(extremFacesMat2[countMat2].getX())[extremFacesMat2[countMat2].getY()],
										matrice2->at(extremFacesMat2[countMat2+1].getX())[extremFacesMat2[countMat2+1].getY()],
										matrice1->at(extremFacesMat1[i+1].getX())[extremFacesMat1[i+1].getY()]);
			countMat2++;
		}


		if (count == nbrFMatrice1+1){
			count = 0;
		}
		else 
			count++;

	}
	std::cout << "coucou2 : " << countMat2 << std::endl;
	std::cout << "coucou2 : " << i << std::endl;
	std::cout << "simplification " << nbrFMatrice1 << ", " << nbrFMatrice2 << std::endl;

	ColorElevationMap::addTriangle(matrice2->at(extremFacesMat2[countMat2].getX())[extremFacesMat2[countMat2].getY()],
										matrice2->at(extremFacesMat2[countMat2+1].getX())[extremFacesMat2[countMat2+1].getY()],
										matrice1->at(extremFacesMat1[i].getX())[extremFacesMat1[i].getY()]);
	std::cout << "coucou3" << std::endl;



}


/*!
* \fn void ColorElevationMap::createMapper()
* \brief  create the mapper
*/
void VolumeVisualisation::createMapper()
{
     // Now we'll look at it.
    m_mapper->SetInputData(m_polyData);
    m_mapper->SetScalarRange(0, 5);
}



/**
*\fn std::vector<std::vector<float> > getContour(std::vector<std::vector<float> > *matrice)
*\brief  
*\param 2 2D vector float (anterior surface, posterior surface)
*/
std::vector<std::vector<float> > VolumeVisualisation::getContour(std::vector<std::vector<float> > *matrice){
	UtilsVectorContour::eraseLine(matrice, 3, m_Null);
	UtilsVectorContour::eraseArmContour(matrice, m_Null );
	UtilsVectorContour::fillHoleInMatrice(matrice,m_Null);
	UtilsVectorContour::fillSurfaceInMatrice(matrice,m_Null);
	return UtilsVectorContour::getContour(matrice,m_Null);
}

/**
*\fn std::vector<std::vector<float> > getContour(std::vector<std::vector<float> > *matrice)
*\brief Build a point vector of all faces extremity 
*\param vector float => begin point
*\param 2D vector float 
*\return point vector
*/
std::vector< Point > VolumeVisualisation::buildVectorOfExtremtyFace(Point* begin, std::vector<std::vector<float> >* matrice)
{
	std::vector<Point> result;
	Point actuel = *begin;
	Point next;
	bool fin = false;
	int direction(0);
	result.push_back(begin);
	do{
		next = VolumeVisualisation::findNextPoint(actuel, matrice, direction, indexNull);
		if (result.size() > 1 && VolumeVisualisation::pointInFace(actuel, next, begin) )
		{
			next = begin;
			fin = true;
		}

		result.push_back(next);
		actuel = next;
	}
	while(fin == false);

	return result;
}

/**
*\fn std::vector<std::vector<float> > getContour(std::vector<std::vector<float> > *matrice)
*\brief Build a point vector of all faces extremity 
*\param vector float => begin point
*\param 2D vector float 
*\return point vector
*/
std::vector< Point > VolumeVisualisation::buildVectorOfExtremtyFace(Point* begin, Point *second, std::vector<std::vector<float> >* matrice)
{
	std::vector<Point> result;
	Point actuel(begin);
	Point next;
	bool fin = false;
	int direction(0);
	result.push_back(actuel);
	

	

	do{
		next = VolumeVisualisation::findNextPoint(actuel, matrice, direction, indexNull);
		if (result.size() > 1 && VolumeVisualisation::pointInFace(actuel, next, begin) )
		{
			next = begin;
			fin = true;
		}

		result.push_back(next);
		actuel = next;
	}
	while(fin == false);

	return result;
}

/**
*\fn std::vector< float > VolumeVisualisation::findNextPoint(std::vector< float > point, std::vector<std::vector<float> > *matrice,
													 int &direction, float valeurNull)
*\brief Constructeur 
*\param 2 2D vector float (anterior surface, posterior surface)
*\param valeurIgnore
*/
Point VolumeVisualisation::findNextPoint(std::vector< float > point, std::vector<std::vector<float> > *matrice,
													 int &direction, float valeurNull)
{

	Point nextPoint;
	float x(point[0]), y(point[1]);

	if (direction == 0)
		direction = UtilsVectorDirection::findType(matrice, point[0], point[1], valeurNull);
	else
		direction = UtilsVectorDirection::findNextAndType(matrice, x, y, -direction, valeurNull);

	while(UtilsVectorDirection::next(matrice, x, y, direction,valeurNull)){}
		
	nextPoint.setCoordonne(x, y, matrice->at(x)[y]);
	return nextPoint;
}


bool VolumeVisualisation::pointInFace(std::vector< float > begin, std::vector< float > end, std::vector< float > point)
{
	if (begin[0] == point[0])
		return (point[1] <= end[1] && point[1] >= begin[1]) || (point[1] >= end[1] && point[1] <= begin[1]);
	if (begin[1] == point[1])
		return (point[0] <= end[0] && point[0] >= begin[0]) || (point[0] >= end[0] && point[0] <= begin[0]);
}


VolumeVisualisation::~VolumeVisualisation(){

}
