#include "SurfaceElevationFromMatrice.h"

/*!
* \fn SurfaceElevationFromMatrice::ColorElevationMap(std::vector<std::vector<float> > matrice, float valeurIgnore)
* \brief constructor of the class ColorElevation Map
* \param matrice of float value
* \param a value which replace the null value
*/
SurfaceElevationFromMatrice::SurfaceElevationFromMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
{
    m_nombrePoint = 0; // coordonnee count initialization
    // peut être inutile ... a voir
    m_maxElevation = UtilsVector::getMax(matrice, valeurIgnore);
    m_minScal  = -m_maxElevation*10;
    std::cout << m_minScal << std::endl;
    m_minElevation = UtilsVector::getMin(matrice, valeurIgnore);
    m_maxScal = -m_minElevation*10;
    std::cout << m_maxScal << std::endl;
    //
    ColorElevationMap::newMap(); // attribute initialization
    SurfaceElevationFromMatrice::mapWithMatrice( matrice, valeurIgnore); // construction of the polydata from the matrice
    ColorElevationMap::createMapper();
    m_actor->SetMapper(m_mapper);
}

/*!
*\fn void SurfaceElevationFromMatrice::mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief visualize a map from a matrice f vector
*\param vector of float vector
*\param the value which replace null
*/
void SurfaceElevationFromMatrice::mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
{
    SurfaceElevationFromMatrice::newCoord(matrice, valeurIgnore);
    SurfaceElevationFromMatrice::newScalar(matrice, valeurIgnore);
    SurfaceElevationFromMatrice::newCells(SurfaceElevationFromMatrice::newIndex(matrice, valeurIgnore));
    // We now assign the pieces to the vtkPolyData.
    m_polyData->SetPoints(m_points);
    m_polyData->SetPolys(m_polys);
    m_polyData->GetPointData()->SetScalars(m_scalars);
}

/*!
*\fn void SurfaceElevationFromMatrice::newCoord(std::vector<std::vector<float> > matrice,float valeurIgnore)
*\brief insert all the point from the matrice in the vtkPoint
*\param matrice : vector of float vector
*\param the value that replace the null
*/
void SurfaceElevationFromMatrice::newCoord(std::vector<std::vector<float> > matrice,float valeurIgnore)
{
  float matSize = (float) matrice.size();

  for (float x = 0; x <  matSize; x++)
    for(float y = 0; y < matSize; y++)
    {
        float z = matrice[x][y];
        if (z != valeurIgnore)
        {
            float coord[3]= {x, y, z*10};
            m_points->InsertPoint(m_nombrePoint++,coord);
        }

    }
}

/*!
* \fn void SurfaceElevationFromMatrice::newScalar(std::vector<std::vector<float> > matrice, float valeurIgnore)
* \brief add scalar value from a matrice
* \param matrice of float value
* \param the value which replace the null value
*/
void SurfaceElevationFromMatrice::newScalar(std::vector<std::vector<float> > matrice, float valeurIgnore)
{
    float matSize = (float) matrice.size();
    int i = 0;
    for (float x = 0; x <  matSize; x++)
        for(float y = 0; y < matSize; y++)
        {
            float z = matrice[x][y];
            if (z != valeurIgnore)
            {
                m_scalars->InsertTuple1(i++,-z*10);
            }
        }

    std::cout << "nombre de coord : " << m_nombrePoint << std::endl;
    std::cout << "nombre de scalar : " << i << std::endl;
}


/*!
*\fn std::vector<std::vector<float> > SurfaceElevationFromMatrice::newIndex(std::vector<std::vector<float> > matrice,float valeurIgnore)
*\brief creat a vector of float vector that contain all the index
*\param matrice : vector of float vector
*\param the value that replace the null
*\return a matrice of index which describe the place of each coordonnate in the list
*/
std::vector<std::vector<float> > SurfaceElevationFromMatrice::newIndex(std::vector<std::vector<float> > matrice,float valeurIgnore)
{
  int i = 0;
  std::vector<std::vector<float> > matriceIndex;
  std::vector<float> matriceTmp;
  float matSize = (float) matrice.size();
  for (float x = 0; x <  matSize; x++)
  {
     for(float y = 0; y < matSize; y++)
        if (matrice[x][y]==valeurIgnore)
          matriceTmp.push_back(-2);
        else
          matriceTmp.push_back(i++);

     if (i != 0)
       matriceIndex.push_back(matriceTmp);

     matriceTmp.clear();
  }
  return matriceIndex;

}

SurfaceElevationFromMatrice::~SurfaceElevationFromMatrice()
{
    //dtor
}
