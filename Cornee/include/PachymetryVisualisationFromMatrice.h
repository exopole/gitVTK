#ifndef PACHYMETRYVISUALISATIONFROMMATRICE_H
#define PACHYMETRYVISUALISATIONFROMMATRICE_H

#include <ColorElevationMap.h>


class PachymetryVisualisationFromMatrice : public ColorElevationMap
{
    public:
        PachymetryVisualisationFromMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore);
        virtual ~PachymetryVisualisationFromMatrice();
    protected:
        void newCells(std::vector<std::vector<float> > matriceIndex);
        void mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore);
        void newCoord(std::vector<std::vector<float> > matrice,float valeurIgnore);
        void newScalar(std::vector<std::vector<float> > matrice, float valeurIgnore);
        std::vector<std::vector<float> > newIndex(std::vector<std::vector<float> > matrice,float valeurIgnore);
        
};

#endif // PachymetryVisualisationFromMatrice_H
