#include "UtilsTableau.h"

UtilsTableau::UtilsTableau()
{
    //ctor
}

/*!
* \fn void UtilsTableau::printFloat2D(float** data, int taille)
* \brief print all value of a matrice
* \param matrice
* \param size of the matrice
*/
void UtilsTableau::printFloat2D(float** data, int taille)
{
    for(int i = 0; i< taille; i++){
        for(int j = 0; j< taille; j++)
            std::cout << data[i][j];
        std::cout << std::endl;
    }
}

/*!
* \fn void UtilsTableau::copieFloat2D(float** init, float** dest, int sizeX, int sizeY)
* \brief copie a 2 D array in another
* \param 2D array original
* \param 2D array of destination
* \param row counts
* \param column counts
*/
void UtilsTableau::copieFloat2D(float** init, float** dest, int sizeX, int sizeY)
{
    for(int i = 0; i < sizeX; i++){
        for (int j(0); j < sizeY; j++)
            dest[i][j] = init[i][j];
    }
}

/*!
* \fn void UtilsTableau::copieFloat2D(float** init, float** dest, int sizeX, int sizeY)
* \brief copie a 2 D array in another
* \param 2D array original
* \param 2D array of destination
* \param row counts (= column counts)
*/
void UtilsTableau::copieFloat2D(float** init, float** dest, int taille)
{
    for(int i = 0; i < taille; i++){
        for (int j(0); j < taille; j++)
            dest[i][j] = init[i][j];
    }
}



UtilsTableau::~UtilsTableau()
{
    //dtor
}
