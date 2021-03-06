#include "AfficherCarre.h"

AfficherCarre::AfficherCarre()
{
       // We'll create the building blocks of polydata including data attributes.
    m_carre = vtkPolyData::New();
    m_points = vtkPoints::New();
    m_polys = vtkCellArray::New();
    m_scalars = vtkFloatArray::New();
    AfficherCarre::carre();
    AfficherCarre::maillageTriangleFromVectorMatrice(matrice);
}

void AfficherCarre::carre()
{
    std::cout << "step 1 "<< std::endl;

    for (int i = -75; i < 75; i++)
    {
        std::vector< float>  matriceTmp;
        for (int j = -75; j < 75; j++)
        {
            matriceTmp.push_back(0);
        }
        matrice.push_back(matriceTmp);
    }

}




void AfficherCarre::maillageTriangleFromVectorMatrice(std::vector<std::vector<float> > matrice )
{
    int i = 0;
    float matSize = (float) matrice.size();
    for (float x = 0; x <  matSize; x++)
    {
        for(float y = 0; y < matSize; y++)
        {

            if (y < matSize-1 && x < matSize -1)
            {
                vtkIdType pts[2][3] = {
                        {i, i+matSize+1, i+1},
                        {i, i+1+matSize, i+matSize}
                                    };
                for (int j = 0; j < 2; j++) m_polys->InsertNextCell(3,pts[j]);
            }
            float z = matrice[x][y];
            float coord[3]= {x, y, z};
            m_scalars->InsertTuple1(i,x-75);
            m_points->InsertPoint(i++,coord);
        }
    }

}


void AfficherCarre::scalarBarBuild(vtkPolyDataMapper *carreMapper)
{
    scalarBar = vtkSmartPointer<vtkScalarBarActor>::New();
    scalarBar->SetLookupTable( carreMapper->GetLookupTable());
    scalarBar->SetTitle("Palette");
    scalarBar->SetNumberOfLabels(5);
}

void AfficherCarre::coloration(){
    
    colorLookupTable = vtkSmartPointer<vtkLookupTable>::New();
    colorLookupTable->SetTableRange(-75,75);
    colorLookupTable->SetHueRange(0.0, 0.667);
    colorLookupTable->SetNumberOfColors(35);
    colorLookupTable->Build();
    

}


void AfficherCarre::visualization()
{
        // We now assign the pieces to the vtkPolyData.
    m_carre->SetPoints(m_points);
    m_carre->SetPolys(m_polys);
    m_carre->GetPointData()->SetScalars(m_scalars);

    // Now we'll look at it.
    vtkPolyDataMapper *carreMapper = vtkPolyDataMapper::New();
    carreMapper->SetInputData(m_carre);
    carreMapper->SetScalarRange(-75,75);
    AfficherCarre::coloration();
    carreMapper->SetLookupTable(colorLookupTable);
    AfficherCarre::scalarBarBuild(carreMapper);

    vtkActor *carreActor = vtkActor::New();
    carreActor->SetMapper(carreMapper);

    // The usual rendering stuff.
    vtkCamera *camera = vtkCamera::New();
    camera->SetPosition(1,1,1);
    camera->SetFocalPoint(0,0,0);

    vtkRenderer *renderer = vtkRenderer::New();
    vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(renderer);

    vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);

    renderer->AddActor(carreActor);
    renderer->AddActor(scalarBar);
    renderer->SetActiveCamera(camera);
    renderer->ResetCamera();
    renderer->SetBackground(1,1,1);

    renWin->SetSize(300,300);

    // interact with data
    renWin->Render();
    iren->Start();

    // Clean up

    m_carre->Delete();
    carreMapper->Delete();
    carreActor->Delete();
    camera->Delete();
    renderer->Delete();
    renWin->Delete();
    iren->Delete();
}

AfficherCarre::~AfficherCarre()
{
    //dtor
}
