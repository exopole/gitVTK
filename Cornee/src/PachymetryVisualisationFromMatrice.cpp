#include "PachymetryVisualisationFromMatrice.h"

PachymetryVisualisationFromMatrice::PachymetryVisualisationFromMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
{
  PachymetryVisualisationFromMatrice::newMap(); // attribute initialization
  PachymetryVisualisationFromMatrice::mapWithMatrice( matrice, valeurIgnore); // construction of the polydata from the matrice
  PachymetryVisualisationFromMatrice::createMapper();
  m_actor->SetMapper(m_mapper);
}

/*!
*\fn void PachymetryVisualisationFromMatrice::mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief visualize a map from a matrice f vector
*\param vector of float vector
*\param the value which replace null
*/
void PachymetryVisualisationFromMatrice::mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
{
    PachymetryVisualisationFromMatrice::newCoord(matrice, valeurIgnore);
    PachymetryVisualisationFromMatrice::newScalar(matrice, valeurIgnore);
    PachymetryVisualisationFromMatrice::newCells(PachymetryVisualisationFromMatrice::newIndex(matrice, valeurIgnore));
    // We now assign the pieces to the vtkPolyData.
    m_polyData->SetPoints(m_points);
    m_polyData->SetPolys(m_polys);
    m_polyData->GetPointData()->SetScalars(m_scalars);
}


/*!
*\fn void ColorElevationMap::newCells(std::vector<std::vector<float> > matriceIndex)
*\brief create new cells for the mesh
*\param matrice of index where -1 => value null
*/
void PachymetryVisualisationFromMatrice::newCells(std::vector<std::vector<float> > matriceIndex)
{
  for(float x = 0;x < (float) matriceIndex.size()-1; x++ )
  {
    for(float y = 0; y < (float) matriceIndex[x].size()-1; y++)
    {
      if (matriceIndex[x][y] > -1)
      {
        //
        // top of the PachymetryVisualisationFromMatrice (functional)
       PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y], matriceIndex[x+1][y+1],matriceIndex[x][y+1] );
        PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y], matriceIndex[x+1][y+1],matriceIndex[x+1][y] );
        // bot of PachymetryVisualisationFromMatrice (not functional)
        PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y]+1, matriceIndex[x+1][y+1]+1,matriceIndex[x][y+1]+1);
        PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y]+1, matriceIndex[x+1][y+1]+1,matriceIndex[x+1][y]+1 );
        //
        PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y], matriceIndex[x+1][y],matriceIndex[x+1][y]+1);
        PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y], matriceIndex[x][y]+1,matriceIndex[x+1][y]+1);
        //
        PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y], matriceIndex[x][y+1],matriceIndex[x][y+1]+1);
        PachymetryVisualisationFromMatrice::addTriangle(matriceIndex[x][y], matriceIndex[x][y]+1,matriceIndex[x][y+1]+1);


      }
    }
  }
}

/*!
*\fn void PachymetryVisualisationFromMatrice::newCoord(std::vector<std::vector<float> > matrice,float valeurIgnore)
*\brief insert all the point from the matrice in the vtkPoint
*\param matrice : vector of float vector
*\param the value that replace the null
*/
void PachymetryVisualisationFromMatrice::newCoord(std::vector<std::vector<float> > matrice,float valeurIgnore)
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
            float coord2[3]= {x, y, 0};
            m_points->InsertPoint(m_nombrePoint++,coord2);
        }
    }
}

/*!

* \fn void PachymetryVisualisationFromMatrice::newScalar(std::vector<std::vector<float> > matrice, float valeurIgnore)
* \brief add scalar value from a matrice
* \param matrice of float value
* \param the value which replace the null value
*/
void PachymetryVisualisationFromMatrice::newScalar(std::vector<std::vector<float> > matrice, float valeurIgnore)
{
    float matSize = (float) matrice.size();
    int i = 0;
    for (float x = 0; x <  matSize; x++)
        for(float y = 0; y < matSize; y++)
        {
            float z = matrice[x][y];
            if (z != valeurIgnore)
            {
                m_scalars->InsertTuple1(i++,-1);
                m_scalars->InsertTuple1(i++,1);
            }
        }

    std::cout << "nombre de coord : " << m_nombrePoint << std::endl;
    std::cout << "nombre de scalar : " << i << std::endl;
}


/*!
*\fn std::vector<std::vector<float> > PachymetryVisualisationFromMatrice::newIndex(std::vector<std::vector<float> > matrice,float valeurIgnore)
*\brief creat a vector of float vector that contain all the index
*\param matrice : vector of float vector
*\param the value that replace the null
*\return a matrice of index which describe the place of each coordonnate in the list
*/
std::vector<std::vector<float> > PachymetryVisualisationFromMatrice::newIndex(std::vector<std::vector<float> > matrice,float valeurIgnore)
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
        {
            matriceTmp.push_back(i);
            i += 2;
        }

     if (i != 0)
       matriceIndex.push_back(matriceTmp);

     matriceTmp.clear();
  }
  return matriceIndex;
}

PachymetryVisualisationFromMatrice::~PachymetryVisualisationFromMatrice()
{
    //dtor
}
