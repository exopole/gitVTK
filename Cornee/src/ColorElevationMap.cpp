#include "ColorElevationMap.h"


/*!
* \fn ColorElevationMap::ColorElevationMap(std::vector<std::vector<float> > matrice, float valeurIgnore)
* \brief constructor of the class ColorElevation Map
* \param matrice of float value
* \param a value which replace the null value
*/
ColorElevationMap::ColorElevationMap()
{
  ColorElevationMap::newMap();
}


/*!
*\fn void ColorElevationMap::newMap()
*\brief initialize all attributs
*/
void ColorElevationMap::newMap()
{
  m_nombrePoint = 0;
  m_polyData = vtkPolyData::New();
  m_points = vtkPoints::New();
  m_polys = vtkCellArray::New();
  m_scalars = vtkFloatArray::New();
  m_mapper = vtkPolyDataMapper::New();
  m_actor = vtkActor::New();
}

/*!
*\fn void ColorElevationMap::newCells(std::vector<std::vector<float> > matriceIndex)
*\brief create new cells for the mesh
*\param matrice of index where -1 => value null
*/
void ColorElevationMap::newCells(std::vector<std::vector<float> >* matriceIndex)
{
  std::cout << "coucou" << std::endl;
  for(float x = 0;x < matriceIndex->size()-1; x++ )
  {
    for(float y = 0; y < matriceIndex->at(x).size()-1; y++)
    {
      ColorElevationMap::addTriangle(matriceIndex->at(x)[y],matriceIndex->at(x+1)[y+1],matriceIndex->at(x)[y+1]);
      ColorElevationMap::addTriangle(matriceIndex->at(x)[y],matriceIndex->at(x+1)[y+1],matriceIndex->at(x+1)[y]);
    }
  }
}


/*!
* \brief create of a triangle cell if non of the points are inferior or equal to -1
* \param coord in the vtkPoint list of the triangle
*/
void ColorElevationMap::addTriangle(float pt1, float pt2, float pt3)
{
  if (pt1 > -1 && pt2 > -1 && pt3 > -1 )
  {
    vtkIdType pts[3] = {pt1, pt2, pt3};
    m_polys->InsertNextCell(3,pts);
  }
}

/*!
* \brief create of a square cell if non of the points are inferior or equal to -1
* \param coord in the vtkPoint list of the triangle
*/
void ColorElevationMap::addSquare(float pt1, float pt2, float pt3, float pt4)
{
  if (pt1 > -1 && pt2 > -1 && pt3 > -1 && pt4 > -1)
  {
    vtkIdType pts[4] = {pt1, pt2, pt3, pt4};
    m_polys->InsertNextCell(4,pts);
  }
}

/*!
* \brief create of a square cell if non of the points are inferior or equal to -1
* \param coord in the vtkPoint list of the triangle
*/
void ColorElevationMap::addCell(float pt1, float pt2, float pt3, float pt4)
{
  if (pt1 < -1)
    ColorElevationMap::addTriangle(pt2,pt3,pt4);
  else if (pt2 < -1)
    ColorElevationMap::addTriangle(pt1,pt3,pt4);
  else if (pt3 < -1)
    ColorElevationMap::addTriangle(pt2,pt1,pt4);
  else if (pt4 < -1)
    ColorElevationMap::addTriangle(pt2,pt3,pt1);
  else
    ColorElevationMap::addSquare(pt1, pt2, pt3, pt4);
}



/*!
* \fn void ColorElevationMap::createMapper()
* \brief  create the mapper
*/
void ColorElevationMap::createMapper()
{
     // Now we'll look at it.
    m_mapper->SetInputData(m_polyData);
    m_mapper->SetScalarRange(m_minScal, m_maxScal);
}



void ColorElevationMap::setLookUpTable(float R[35], float G[35], float B[35]){
    
    lut = vtkLookupTable::New();
    lut->SetTableRange(0,35); 
    lut->SetNumberOfColors(35); 
    lut->Build(); 
    for (int i = 0; i < 35; i++)
    {
      lut->SetTableValue(i, R[i]/255, G[i]/255, B[i]/255); 
    }
    m_mapper->SetLookupTable(lut);

}

/*!
*\fn vtkPolyData* ColorElevationMap::getPolyData()
*\brief get the polydata of the map
*\return polydata of the map
*/
vtkPolyData * ColorElevationMap::getPolyData()
{
  return m_polyData;
}

/*!
*\fn vtkPolyData* ColorElevationMap::setPolyData()
*\brief get the polydata of the map
*/
void ColorElevationMap::setPolyData(vtkPolyData * polyData)
{
  m_polyData=polyData;
}

/*!
*\fn vtkPoints* ColorElevationMap::getPoints()
*\brief get the points of the map
*\return points of the map
*/
vtkPoints * ColorElevationMap::getPoints()
{
  return m_points;
}

/*!
*\fn vtkPoints* ColorElevationMap::setPoints()
*\brief set the points of the map
*\return points of the map
*/
void ColorElevationMap::setPoints(vtkPoints * points)
{
  m_points = points;
}

/*!
*\fn vtkActor* ColorElevationMap::getPolys()
*\brief get the actor of the map
*\return actor of the map
*/
vtkCellArray * ColorElevationMap::getPolys()
{
  return m_polys;
}

/*!
*\fn vtkActor* ColorElevationMap::setPolys()
*\brief set the actor of the map
*/
void ColorElevationMap::setPolys(vtkCellArray * polygone)
{
  m_polys = polygone ;
}

/*!
*\fn vtkFloatArray* ColorElevationMap::getScalar()
*\brief get the actor of the map
*\return actor of the map
*/
vtkFloatArray * ColorElevationMap::getScalar()
{
  return m_scalars;
}

/*!
*\fn vtkFloatArray* ColorElevationMap::setScalar()
*\brief set the actor of the map
*/
void ColorElevationMap::setScalar(vtkFloatArray * scalars)
{
  m_scalars=scalars;
}

/*!
*\fn vtkPolyDataMapper* ColorElevationMap::getMapper()
*\brief get the mapper
*\return mapper of the map
*/
vtkPolyDataMapper* ColorElevationMap::getMapper()
{
  return m_mapper;
}

/*!
*\fn vtkPolyDataMapper* ColorElevationMap::setMapper()
*\brief set the mapper
*/
void ColorElevationMap::setMapper(vtkPolyDataMapper* mapper)
{
  m_mapper = mapper;
}

/*!
*\fn vtkActor* ColorElevationMap::getActor()
*\brief get the actor of the map
*\return actor of the map
*/
vtkActor* ColorElevationMap::getActor()
{
  return m_actor;
}

/*!
*\fn vtkActor* ColorElevationMap::setActor()
*\brief set the actor of the map
*/
void ColorElevationMap::setActor(vtkActor* actor)
{
  m_actor = actor;
}


/*!
* \fn void writeVTPfile(std::string namefile)
* \brief write the polydata object in a file
* \param name of the output file
*/
void ColorElevationMap::writeData(std::string namefile)
{
    UtilsVTK::writeVTPfile(namefile, m_polyData);
}

void ColorElevationMap::scalarBarBuild()
{
    scalarBar = vtkSmartPointer<vtkScalarBarActor>::New();
    scalarBar->SetLookupTable( m_mapper->GetLookupTable());
    scalarBar->SetTitle("Palette (µm)");
    scalarBar->SetNumberOfLabels(11);
}


void ColorElevationMap::visualisation()
{

  
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =  vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderer->AddActor(m_actor);
  renderer->SetBackground(1, 1,1); // Background color green

  renderWindow->Render();
  renderWindowInteractor->Start();

}


void ColorElevationMap::visualisationWithScalarBar()
{

  ColorElevationMap::scalarBarBuild();
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =  vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderer->AddActor(m_actor);

  renderer->AddActor(scalarBar);
  renderer->SetBackground(0, 0,0); // Background color green

  renderWindow->Render();
  renderWindow->SetSize(400,300);
  renderWindowInteractor->Start();

}




ColorElevationMap::~ColorElevationMap()
{
    //dtor
}
