
// include these define if you don't use cmake

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "ParserTopos.h"
#include "SurfaceElevationFromMatrice.h"
#include "SurfaceScalarFromMatrice.h"
#include "PachymetryVisualisationFromMatrice.h"
#include "PachymetryVisualisation.h"
#include "DataPachymetry.h"
#include "UtilsVectorContour.h"
#include "VolumeVisualisation.h"




int main(int argc, char *argv[])
{


    float cR[35] = {180, 160, 140, 120, 100,  60,  40,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 220, 200, 180, 160, 140, 120, 100};
    float cG[35] = {  0,   0,   0,   0,   0,   0,  20,  75,  93, 112, 131, 150, 169, 188, 207, 226, 245, 220, 245, 223, 201, 179, 157, 134, 112,  90,  68,  45,   0,   0,  20,  40,  60,  60,  60};
    float cB[35] = {175, 175, 175, 175, 175, 200, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  40,  60,  80, 100, 100, 100};
/*
    float R[35] = {198, 189, 180, 170, 149, 130, 100,  80,  39,  40,  40,  39,  29, 14,   0,   0,   0,  19,  90, 141, 240, 254, 220, 219, 220, 220, 219, 200, 180, 160, 140, 170, 200, 220, 230};
    float G[35] = {106,  80,  59,  39,  40,  40,  40,  39,   0,   0,  60, 100, 120, 159, 189, 210, 240, 210, 229, 245 254, 231, 199, 170, 141, 110,  80, 50,  0,   0,  59,  80, 100, 119, 140};
    float B[35] = {247, 240, 220, 200, 179, 159, 159, 140, 150, 189, 220, 219, 241, 240, 240, 240, 240,  80,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0,   0,   0,  59,  80, 100, 119, 141};
*/
    float R[35] = {230,220,200,170,140,160,180,200,219,220,220,219,220,254,240,141,90,19,0,0,0,14,29,39,40,40,39,80,100,130,149,170,180,189,198};
    float G[35] = {140,119,100,80,59,0,0,50,80,110,141,170,199,231,254,245,229,210,240,210,189,159,120,100,60,0,0,39,40,40,40,39,59,80,106};
    float B[35] = {141,119,100,80,59, 0,0,0,0,0,0,0,0,0,0,0,0, 80,240,240,240,240,241,219,220,189,150,140,159,159,179,200,220,240,247};



    // test si un argument a été mis au niveau de
    if(argc <= 1)
    {
        std::cout << "Usage: " << argv[0] << " File Topos.txt" << std::endl;
        return EXIT_FAILURE;
    }
  std::string filename = argv[1];
  //  std::string filetest = argv[2];

    std::ifstream fichier(filename.c_str());

    // si le fichier existe bien
    if (fichier)
    {

        std::vector<vtkSmartPointer<vtkActor> > actorVecteur;


        ////////////////////////// Pareser du topo file /////////////////////////////

        ParserTopos newTopos(filename);
        
        //////////////////////////  Scalar visualization /////////////////////////

        
        SurfaceScalarFromMatrice newElevationAnt(newTopos.getAnteriorData(), newTopos.getAnteriorBFSData(), -75, 75, cR, cG, cB, 99.9);
        //newElevationAnt.visualisationWithScalarBar();
        //UtilsVTK::visualisation(newElevationAnt.getActor());
        
        SurfaceScalarFromMatrice newElevationPost(newTopos.getPosteriorData(), newTopos.getPosteriorBFSData(), -75, 75, cR, cG, cB, 99.9);
        //newElevationPost.visualisationWithScalarBar();
        //UtilsVTK::visualisation(newElevationPost.getActor());
        
        
        ////////////////////////// Volume //////////////////////////////////////

        actorVecteur.push_back(newElevationAnt.getActor());
        actorVecteur.push_back(newElevationPost.getActor());
        //UtilsVTK::visualisation(actorVecteur);

        //UtilsVector::printVector(UtilsVector::getContour(newTopos.getPosteriorData(),99.9 ), 99.9);
        VolumeVisualisation newVolume(newTopos.getAnteriorData(), newTopos.getPosteriorData(), 99.9);
        //UtilsVTK::visualisation(newVolume.getActor());
        
        actorVecteur.push_back(newVolume.getActor());


        UtilsVTK::visualisation(actorVecteur);

        ///////////////////////// Pachymetry ////////////////////////////////////
        /*
        DataPachymetry newPachy(&newTopos,  99.9);
        SurfaceScalarFromMatrice newElevationPachy(newPachy.getAnterior(), newPachy.getPachymetry(), 3000, 9000, R, G, B, 99.9);
        //UtilsVector::printVector(newTopos.getPachymetry());
        newElevationPachy.visualisationWithScalarBar();

        */




    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }

    return 0;
}


