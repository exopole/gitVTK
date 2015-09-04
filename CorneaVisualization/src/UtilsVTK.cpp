#include "UtilsVTK.h"

UtilsVTK::UtilsVTK()
{
    //ctor
}


/*!
* \fn void writeVTPfile(std::string namefile)
* \brief write the polydata object in a file
* \param name of the output file
*/
void UtilsVTK::writeVTPfile(std::string namefile, vtkPolyData* polydata )
{
    vtkSmartPointer<vtkXMLPolyDataWriter> writer = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
    writer->SetFileName(namefile.c_str());
    writer->SetInputData(polydata);

    // Optional - set the mode. The default is binary.
    //writer->SetDataModeToBinary();
    //writer->SetDataModeToAscii();
    writer->Write();
}

/*!
*\fn void UtilsVTK::readVTPfile(std::string namefile)
*\brief read a vtp file (vtk format) and make a visualization
*\param name of the file
*/
void UtilsVTK::readVTPfile(std::string namefile)
{
  // Read all the data from the file
  vtkSmartPointer<vtkXMLPolyDataReader> reader = vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(namefile.c_str());
  reader->Update();
  // Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
  mapper->SetScalarRange(-0.23, 0.23);

  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

  UtilsVTK::visualisation(actor);

}

/*!
*\fn void UtilsVTK::visualisation(vtkSmartPointer<vtkActor> actor)
*\brief visualisation of a vtk actor
*\param vtkSmartPointer<vtkActor> actor
*/
void UtilsVTK::visualisation(vtkSmartPointer<vtkActor> actor)
{

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =  vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderer->AddActor(actor);
  renderer->SetBackground(.0, .0, .0); // Background color green

  renderWindow->Render();
  renderWindowInteractor->Start();

}

/*!
*\fn void UtilsVTK::visualisation(vtkSmartPointer<vtkActor> actor)
*\brief visualisation of a vtk actor
*\param vtkSmartPointer<vtkActor> actor
*/
void UtilsVTK::visualisation(vtkSmartPointer<vtkActor> actor, vtkSmartPointer<vtkActor> actor2)
{

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =  vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  renderer->AddActor(actor);
  renderer->AddActor(actor2);
  renderer->SetBackground(.0, .0, .0); // Background color green

  renderWindow->Render();
  renderWindowInteractor->Start();

}


UtilsVTK::~UtilsVTK()
{
    //dtor
}
