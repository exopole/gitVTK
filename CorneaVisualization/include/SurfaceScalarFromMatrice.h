#ifndef SURFACESCALARFROMMATRICE_H
#define SURFACESCALARFROMMATRICE_H

#include <SurfaceElevationFromMatrice.h>


class SurfaceScalarFromMatrice : public SurfaceElevationFromMatrice
{
    public:
        SurfaceScalarFromMatrice(std::vector<std::vector<float> > matrice, std::vector<std::vector<float> > matriceScalar, float valeurIgnore);
        virtual ~SurfaceScalarFromMatrice();
    protected:
      void mapWithMatrice(std::vector<std::vector<float> > matrice, std::vector<std::vector<float> > matriceScalar,float valeurIgnore);
    private:
};

#endif // SURFACESCALARFROMMATRICE_H
