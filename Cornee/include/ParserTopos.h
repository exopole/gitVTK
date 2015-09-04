#ifndef PARSERTOPOS_H
#define PARSERTOPOS_H

#include "DataCornee.h"
#include "fstream"
#include "ParserString.h"
#include "Point.h"
#include "UtilsFile.h"
#include "UtilsVector.h"
#include "UtilsTableau.h"
#include "vector"



/**
*\file ParserTopos.cpp
*\brief Objet permettant de parser un fichier topos.txt et d'en ressortir toutes les informations intéressantes
*\author Alexandre.N
*\date 22/05/15
*
*Objet to parse a Topo file
*/

const std::string  delimiterFile("::"); // délimiteur permettant d'extraire les differents types de valeurs
const char delimiterList(','); // delimiteur permettant d'extraire les valeurs d'élévation
const float VALEURNULL(99.9); // valeur qui remplace les valeur nuls
const int NBRPTSCOORD(3); // nombre de point contenu par les coordonnée
class ParserTopos
{

    public:
        ParserTopos(std::string);
        virtual ~ParserTopos();
        /*
        * return :
        *       True Elevation Anterior
        *       True Elevation Posterior
        *       Anterior Best Fit Sphere
        *       Posterior Best Fit Sphere
        *       Anterior Tangential
        *       Posterior Tangential
        *       0.92 Pachymetry
        */
        void printAllDataName();
        void printDataByName(std::string name);
        void getAllDataName(std::vector<std::string> dest);
        bool getDataByName(std::string name, float dest[SIZEMAX][SIZEMAX]);
        bool getDataByNumber(int number, float dest[SIZEMAX][SIZEMAX]);
        bool getAnteriorData(float dest[SIZEMAX][SIZEMAX]);
        bool getPosteriorData(float dest[SIZEMAX][SIZEMAX]);
        bool getAnteriorBFSData(float dest[SIZEMAX][SIZEMAX]);
        bool getPosteriorBFSData(float dest[SIZEMAX][SIZEMAX]);
        bool getAnteriorTangentialData(float dest[SIZEMAX][SIZEMAX]);
        bool getPosteriorTangentialData(float dest[SIZEMAX][SIZEMAX]);
        bool getPachymetry(float dest[SIZEMAX][SIZEMAX]);
        std::vector<std::vector<float> > getDataByName(std::string name);
        std::vector<std::vector<float> > getDataByNumber(int number);
        std::vector<std::vector<float> > getAnteriorData();
        std::vector<std::vector<float> > getPosteriorData();
        std::vector<std::vector<float> > getAnteriorBFSData();
        std::vector<std::vector<float> > getPosteriorBFSData();
        std::vector<std::vector<float> > getAnteriorTangentialData();
        std::vector<std::vector<float> > getPosteriorTangentialData();
        std::vector<std::vector<float> > getPachymetry();
        std::vector<float>* getCoordXY();
        Point* getCoordBFSAnterior();
        Point* getCoordBFSPosterior();
        float getRadiusBFSAnterior();
        float getRadiusBFSPosterior();
        
        

    protected:
    private:
        void readToposFile(); /// Parsing of the topos file
        bool buildMatrice(int* index, std::vector<std::vector<std::string> > stringList, float matriceValeur[SIZEMAX][SIZEMAX]);
        std::vector<DataCornee> dataList ; /// list of all matrice 101*101 of the file
        std::string nameFile; /// Name of the topos file
        float radiusBFSAnterior;
        float radiusBFSPosterior;
        Point coordBFSAnterior; // coord of the anterior BFS center
        Point coordBFSPosterior; // coord of the posterior BFS center
        std::vector<float> coordXY;

};

#endif // PARSERTOPOS_H
