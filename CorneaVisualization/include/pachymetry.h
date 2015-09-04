#ifndef PACHYMETRY_H
#define PACHYMETRY_H

#include <ColorElevationMap.h>


class pachymetry : public ColorElevationMap
{
    public:
        pachymetry(std::vector<std::vector<float> > matrice, float valeurIgnore);
        virtual ~pachymetry();
    protected:
        void newCells(std::vector<std::vector<float> > matriceIndex);
        void mapWithMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore);
        void newCoord(std::vector<std::vector<float> > matrice,float valeurIgnore);
        void newScalar(std::vector<std::vector<float> > matrice, float valeurIgnore);
        std::vector<std::vector<float> > newIndex(std::vector<std::vector<float> > matrice,float valeurIgnore);
    private:
};

#endif // PACHYMETRY_H
