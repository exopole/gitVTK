#ifndef AFFICHERCARRECTF_H
#define AFFICHERCARRECTF_H


#include "vector"
//include the required header files for the vtk classes we are using
#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCellArray.h"
#include "vtkFloatArray.h"
#include <vtkLookupTable.h>
#include "vtkPointData.h"
#include "vtkPoints.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include <vtkScalarBarActor.h>
#include <vtkSmartPointer.h>

#include "AfficherCarre.h"

class AfficherCarreCTF
{
public:
	AfficherCarreCTF();
	AfficherCarreCTF(float R[35], float G[35], float B[35]);
	~AfficherCarreCTF();
        void carre();
      //  void carre3();
        void visualization();
    protected:
        void maillageTriangleFromVectorMatrice(std::vector<std::vector<float> > matrice);

        void scalarBarBuild(vtkPolyDataMapper *carreMapper);

        void coloration();
        void coloration(float R[35],float G[35],float B[35]);
        vtkPolyData *m_carre;
        vtkPoints *m_points;
        vtkCellArray *m_polys;
        vtkFloatArray *m_scalars;
        vtkSmartPointer<vtkScalarBarActor> scalarBar;
        vtkLookupTable* lut;
        std::vector<std::vector<float> > matrice;
    private:

	
};

#endif