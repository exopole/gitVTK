#ifndef SURFACESCALARFROMMATRICE_H
#define SURFACESCALARFROMMATRICE_H

#include <SurfaceElevationFromMatrice.h>


class SurfaceScalarFromMatrice : public SurfaceElevationFromMatrice
{
    public:
        SurfaceScalarFromMatrice(std::vector<std::vector<float> > matrice, std::vector<std::vector<float> >  matriceScalar, float valeurIgnore);
		SurfaceScalarFromMatrice( std::vector<std::vector<float> > matrice, std::vector<std::vector<float> > matriceScalar, float min, float max, float R[35], float G[35], float B[35], float valeurIgnore);

        virtual ~SurfaceScalarFromMatrice();
    protected:
      void mapWithMatrice(std::vector<std::vector<float> >* matrice, std::vector<std::vector<float> >* matriceScalar,float valeurIgnore);
    private:
};

#endif // SURFACESCALARFROMMATRICE_H
