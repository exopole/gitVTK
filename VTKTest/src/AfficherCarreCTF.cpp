#include "AfficherCarreCTF.h" 


AfficherCarreCTF::AfficherCarreCTF()
{
       // We'll create the building blocks of polydata including data attributes.
    m_carre = vtkPolyData::New();
    m_points = vtkPoints::New();
    m_polys = vtkCellArray::New();
    m_scalars = vtkFloatArray::New();
    AfficherCarreCTF::carre();
    AfficherCarreCTF::maillageTriangleFromVectorMatrice(matrice);
    AfficherCarreCTF::coloration();
}

AfficherCarreCTF::AfficherCarreCTF(float R[35], float G[35], float B[35])
{
       // We'll create the building blocks of polydata including data attributes.
    m_carre = vtkPolyData::New();
    m_points = vtkPoints::New();
    m_polys = vtkCellArray::New();
    m_scalars = vtkFloatArray::New();
    AfficherCarreCTF::carre();
    AfficherCarreCTF::maillageTriangleFromVectorMatrice(matrice);
    AfficherCarreCTF::coloration(R,G,B);
}

void AfficherCarreCTF::carre()
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





void AfficherCarreCTF::maillageTriangleFromVectorMatrice(std::vector<std::vector<float> > matrice )
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


void AfficherCarreCTF::scalarBarBuild(vtkPolyDataMapper *carreMapper)
{
    scalarBar = vtkSmartPointer<vtkScalarBarActor>::New();
    scalarBar->SetLookupTable( carreMapper->GetLookupTable());
    scalarBar->SetTitle("Palette");
    scalarBar->SetNumberOfLabels(11);
}

void AfficherCarreCTF::coloration(){
    
    lut = vtkSmartPointer<vtkLookupTable>::New();
     lut->SetTableRange(0, 3); 
    lut->SetNumberOfColors(3); 
    lut->Build(); 
    lut->SetTableValue(0, 1, 0, 0, 1); 
    lut->SetTableValue(1, 0, 1, 0, 1); 
    lut->SetTableValue(2, 0, 0, 1, 1); 
    

}
void AfficherCarreCTF::coloration(float R[35], float G[35], float B[35]){
    
    lut = vtkSmartPointer<vtkLookupTable>::New();
     lut->SetTableRange(0,35); 
    lut->SetNumberOfColors(35); 
    lut->Build(); 
    for (int i = 0; i < 35; i++)
    {
    	lut->SetTableValue(i, R[i]/255, G[i]/255, B[i]/255); 
    }
    

}


void AfficherCarreCTF::visualization()
{
        // We now assign the pieces to the vtkPolyData.
    m_carre->SetPoints(m_points);
    m_carre->SetPolys(m_polys);
    m_carre->GetPointData()->SetScalars(m_scalars);

    // Now we'll look at it.
    vtkPolyDataMapper *carreMapper = vtkPolyDataMapper::New();
    carreMapper->SetInputData(m_carre);
    carreMapper->SetScalarRange(-75,75);
    carreMapper->SetLookupTable(lut);
    AfficherCarreCTF::scalarBarBuild(carreMapper);

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

AfficherCarreCTF::~AfficherCarreCTF()
{
    //dtor
}

