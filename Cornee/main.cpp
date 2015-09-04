
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
        
        //std::cout << "Etape 1 : "<< std::endl;
        ParserTopos newTopos(filename);
        //std::cout << "Etape 2 : "<< std::endl;
        //newTopos.printAllDataName();
        //UtilsVector::printVector(UtilsVector::getContour(newTopos.getPosteriorData(),99.9 ), 99.9);
        VolumeVisualisation newVolume(newTopos.getAnteriorData(), newTopos.getPosteriorData(), 99.9);
        UtilsVTK::visualisation(newVolume.getActor());
        




    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }

    return 0;
}


