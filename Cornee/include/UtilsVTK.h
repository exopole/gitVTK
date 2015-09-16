#ifndef UTILSVTK_H
#define UTILSVTK_H

#include <vtkActor.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkVersion.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>



class UtilsVTK
{
    public:
        UtilsVTK();
        virtual ~UtilsVTK();
        static void writeVTPfile(std::string namefile, vtkPolyData* polydata);
        static void readVTPfile(std::string namefile);
        static void visualisation(vtkSmartPointer<vtkActor> actor);
        static void visualisation(vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkActor> actor2);
        static void visualisation(vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkActor> actor2, vtkSmartPointer<vtkActor> actor3);
        static void visualisation(std::vector <vtkSmartPointer<vtkActor> > vecteurActor );

    protected:
    private:
};

#endif // UTILSVTK_H
