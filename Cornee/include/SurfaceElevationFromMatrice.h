#ifndef SURFACEELEVATIONFROMMATRICE_H
#define SURFACEELEVATIONFROMMATRICE_H

#include <ColorElevationMap.h>

class SurfaceElevationFromMatrice : public ColorElevationMap
{
    public:
        SurfaceElevationFromMatrice(std::vector<std::vector<float> > matrice, float valeurIgnore);
        virtual ~SurfaceElevationFromMatrice();
    protected:
      void mapWithMatrice(std::vector<std::vector<float> >* matrice, float valueIgnore);
      void newCoord(std::vector<std::vector<float> >* matrice, float valueIgnore);
      void newScalar(std::vector<std::vector<float> >* matrice,float valeurIgnore);
      std::vector<std::vector<float> > newIndex(std::vector<std::vector<float> >* matrice,float valeurIgnore);
      std::vector<std::vector<float> > index;
      float m_maxElevation;
      float m_minElevation;
    private:

};

#endif // SURFACEELEVATIONFROMMATRICE_H
