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
      void setActor(vtkActor* actor);
      void setPolyData(vtkPolyData * polyData);
      void setPoints(vtkPoints * points);
      void setPolys(vtkCellArray * polygone);
      void setScalar(vtkFloatArray * scalars);
      void setMapper(vtkPolyDataMapper* mapper);
      vtkPoints * getPoints();
      vtkFloatArray * getScalar();
      vtkCellArray * getPolys();
      vtkPolyData * getPolyData();
      vtkPolyDataMapper* getMapper();
      vtkActor* getActor();
    protected:
      void newMap();
      void newCells(std::vector<std::vector<float> >* matriceIndex);
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
      float m_Null;
    private:

};

#endif // COLORELEVATIONMAP_H
