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
	//UtilsVector::printVector(&anteriorContour, m_Null);
	//std::cout << "/////////////////" << std::endl;
	//UtilsVector::printVector(&posteriorContour, m_Null);
	
	pointsConfluence = UtilsVector::findPointWithLessDistance(&anteriorContour, &posteriorContour, m_Null);

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
	std::vector<Point> coordContourAnt, coordContourPost;
	
	Point beginAntIndex(&pointsConfluence[0]);
	beginAntIndex.setZ(anteriorIndex[beginAntIndex.getX()][beginAntIndex.getY()]);
	Point beginPostIndex(&pointsConfluence[1]);
	beginPostIndex.setZ(anteriorIndex[beginPostIndex.getX()][beginPostIndex.getY()]);

	coordContourAnt = UtilsVectorContour::getCoordContourFromPoint(&anteriorIndex, &beginAntIndex, indexNull);
	coordContourPost = UtilsVectorContour::getCoordContourFromPoint(&posteriorIndex, &beginPostIndex, indexNull);

	if (coordContourAnt.size() > coordContourPost.size())
	{
		VolumeVisualisation::newCellsVolume(&coordContourAnt,&coordContourPost);
	}
	else if (coordContourAnt.size() < coordContourPost.size())
	{
		VolumeVisualisation::newCellsVolume(&coordContourPost,&coordContourAnt);
	}
	else 
	{
		VolumeVisualisation::newCellsVolume(&coordContourAnt,&coordContourPost);
	}
}

/*!
*\fn void ColorElevationMap::newCells(std::vector<std::vector<float> > matriceIndex)
*\brief create new cells for the mesh
*\param matrice of index where -1 => value null
*/
void VolumeVisualisation::newCellsVolume(std::vector<Point >* matrice1,	std::vector<Point >* matrice2)
{

	int count(0), countMat2(0), i;


	int division =  matrice1->size() / (matrice1->size() - matrice2->size());
	int iterateur;
	int fin;

	if (VolumeVisualisation::sameSens(matrice1, matrice2))
	{
		iterateur = 1;
		fin = matrice2->size()-2;
	}
	else{
		countMat2 = matrice2->size()-1;
		iterateur = -1;
		fin = 2;
	}


	for (i = 0; i < matrice1->size()-1; i++)
	{
		ColorElevationMap::addTriangle(matrice1->at(i).getZ(),
										matrice1->at(i+1).getZ(),
										matrice2->at(countMat2).getZ());
		if (countMat2 != fin && i % division != 0)
		{
			ColorElevationMap::addTriangle(matrice2->at(countMat2).getZ(),
										matrice2->at(countMat2+iterateur).getZ(),
										matrice1->at(i+1).getZ());
			countMat2 += iterateur;
		}




	}

	ColorElevationMap::addTriangle(matrice2->at(countMat2).getZ(),
										matrice2->at(countMat2+iterateur).getZ(),
										matrice1->at(i).getZ());
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
	UtilsVector::printVector(matrice, 99.9);
	UtilsVectorContour::eraseLine(matrice, 3, m_Null);
	UtilsVectorContour::eraseArmContour(matrice, m_Null );
	UtilsVectorContour::fillHoleInMatrice(matrice,m_Null);
	UtilsVectorContour::fillSurfaceInMatrice(matrice,m_Null);
	return UtilsVectorContour::getContour(matrice,m_Null);
}





/**
*\fn std::vector< float > VolumeVisualisation::findNextPoint(std::vector< float > point, std::vector<std::vector<float> > *matrice,
													 int &direction, float valeurNull)
*\brief Constructeur 
*\param 2 2D vector float (anterior surface, posterior surface)
*\param valeurIgnore
*/
Point VolumeVisualisation::findNextPoint(Point* point, std::vector<std::vector<float> > *matrice,
													 int &direction, float valeurNull)
{

	Point nextPoint;
	float x(point->getX()), y(point->getY());

	if (direction == 0)
		direction = UtilsVectorDirection::findType(matrice, x, y, valeurNull);
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


bool VolumeVisualisation::sameSens(std::vector<Point >* matrice1, std::vector<Point >* matrice2)
{
	return UtilsGeometry::distanceBetween3DPoint(&(matrice1->at(matrice1->size()/4)), &(matrice2->at(matrice1->size()/4)) ) < 
		   UtilsGeometry::distanceBetween3DPoint(&(matrice1->at(matrice1->size()/4)), &(matrice2->at(3*matrice1->size()/4)) ) ;
}


VolumeVisualisation::~VolumeVisualisation(){

}
