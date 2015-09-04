#include "SurfaceScalarFromMatrice.h"


/*!
* ColorElevationMap::ColorElevationMap(std::vector<std::vector<float> > matrice, std::vector<std::vector<float> > matriceScalar, float valeurIgnore)
* \brief constructor of the class ColorElevation Map
* \param matrice of float value for the coordonee
* \param matrice of float value for scalar
* \param a value which replace the null value
*/
SurfaceScalarFromMatrice::SurfaceScalarFromMatrice( std::vector<std::vector<float> > matrice, std::vector<std::vector<float> > matriceScalar, float valeurIgnore): SurfaceElevationFromMatrice(matrice, valeurIgnore)
{
    m_nombrePoint = 0;
    m_maxElevation = UtilsVector::getMax(matrice, valeurIgnore);
    m_minScal = -1*UtilsVector::getMax(matriceScalar, valeurIgnore);
    m_minElevation = UtilsVector::getMin(matrice, valeurIgnore);
    m_maxScal = -1*UtilsVector::getMin(matriceScalar, valeurIgnore);
    if (m_minScal*-1 < m_maxScal) m_minScal = -1*m_maxScal;
    else m_maxScal = -1*m_minScal;
    SurfaceScalarFromMatrice::newMap();
    SurfaceScalarFromMatrice::mapWithMatrice( matrice, matriceScalar, valeurIgnore);
    SurfaceScalarFromMatrice::createMapper();
    m_actor->SetMapper(m_mapper);
}

/*!
*\fn void SurfaceScalarFromMatrice::mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief visualize a map from a matrice f vector
*\param vector of float vector
*\param the value which replace null
*/
void SurfaceScalarFromMatrice::mapWithMatrice(std::vector<std::vector<float> > matrice, std::vector<std::vector<float> > matriceScalar,float valeurIgnore)
{
    SurfaceScalarFromMatrice::newCoord(matrice, valeurIgnore);
    SurfaceScalarFromMatrice::newScalar(matriceScalar, valeurIgnore);
    SurfaceScalarFromMatrice::newCells(SurfaceScalarFromMatrice::newIndex(matrice, valeurIgnore));
    // We now assign the pieces to the vtkPolyData.
    m_polyData->SetPoints(m_points);
    m_polyData->SetPolys(m_polys);
    m_polyData->GetPointData()->SetScalars(m_scalars);
}

SurfaceScalarFromMatrice::~SurfaceScalarFromMatrice()
{
    //dtor
}
