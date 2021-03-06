#ifndef AFFICHERCARRE_H
#define AFFICHERCARRE_H


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


class AfficherCarre
{
    public:
        AfficherCarre();
        virtual ~AfficherCarre();
        void carre();
      //  void carre3();
        void visualization();
    protected:
        void maillageTriangleFromVectorMatrice(std::vector<std::vector<float> > matrice);

        void scalarBarBuild(vtkPolyDataMapper *carreMapper);

        void coloration();

        vtkPolyData *m_carre;
        vtkPoints *m_points;
        vtkCellArray *m_polys;
        vtkFloatArray *m_scalars;
        vtkSmartPointer<vtkScalarBarActor> scalarBar;
        vtkSmartPointer<vtkLookupTable> colorLookupTable;
        std::vector<std::vector<float> > matrice;
    private:

};

#endif // AFFICHERCARRE_H
