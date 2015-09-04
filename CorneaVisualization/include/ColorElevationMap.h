#ifndef COLORELEVATIONMAP_H
#define COLORELEVATIONMAP_H

//include the required header files for the vtk classes we are using
#include "vtkCamera.h"
#include "vtkCellArray.h"
#include "vtkCommand.h"
#include "vtkFloatArray.h"
#include "vtkPointData.h"
#include "vtkPoints.h"
#include "UtilsVTK.h"


//include utils
#include "UtilsVector.h"

class ColorElevationMap
{
    public:
      ColorElevationMap();
      virtual ~ColorElevationMap();
      void writeData(std::string namefile);
      vtkActor* getActor();
      void setActor(vtkActor* actor);
      vtkPolyData * getPolyData();
      void setPolyData(vtkPolyData * polyData);
      vtkPoints * getPoints();
      void setPoints(vtkPoints * points);
      vtkCellArray * getPolys();
      void setPolys(vtkCellArray * polygone);
      vtkFloatArray * getScalar();
      void setScalar(vtkFloatArray * scalars);
      vtkPolyDataMapper* getMapper();
      void setMapper(vtkPolyDataMapper* mapper);
    protected:
      void newMap();
      void newCells(std::vector<std::vector<float> > matriceIndex);
      void addTriangle(float pt1, float pt2, float pt3);
      void addCell(float pt1, float pt2, float pt3, float pt4);
      void addSquare(float pt1, float pt2, float pt3, float pt4);
      void createMapper();
      vtkPolyData *m_polyData;
      vtkPoints *m_points;
      vtkCellArray *m_polys;
      vtkFloatArray *m_scalars;
      vtkPolyDataMapper *m_mapper;
      vtkActor *m_actor;
      float m_nombrePoint;
      float m_minScal;
      float m_maxScal;
    private:

};

#endif // COLORELEVATIONMAP_H
