#include "UtilsVector.h"

UtilsVector::UtilsVector()
{
    //ctor
}



/***
*\fn void ParserString::vectorToString(std::vector <std::string>* vectorResult)
*\brief Print a vector
*\param a vector of string
*\return nothing
*/
void UtilsVector::stringVectorToString(std::vector <std::string>* vectorResult)
{

    for (int i = 0 ; i < (int)vectorResult->size(); i++)
    {
        std::cout << (*vectorResult)[i] +" "     ;
    }
    std::cout << std::endl;

}


/***
*\fn void ParserString::vectorOfVectorToString(std::vector<std::vector <std::string> >* vectorResult)
*\brief Print a vector of vector
*\param a pointer from a vector of string vector
*\return nothing
*
*use    vectorToString
*/
void UtilsVector::vectorOfStringVectorToString(std::vector<std::vector <std::string> >* vectorResult)
{

    for (int i = 0 ; i < (int)vectorResult->size(); i++)
    {
        UtilsVector::stringVectorToString(&(*vectorResult)[i]);
    }

}


/***
*\fn void ParserString::vecteurStringTofloatArray(std::vector<std::string> vecteur, float[] arr)
*\brief add float in a array from a vector of string
*\param string vector and a float array
*\return nothing
*
*use stringToFloat
*/
void UtilsVector::vecteurStringTofloatArray(std::vector<std::string> vecteur, float arr[101], float valeurNull)
{
    for(int i = 0; i< (int)vecteur.size(); i++)
    {

        if (vecteur[i] == "NULL")
            arr[i] =valeurNull;
        else
        {
            arr[i]  = ParserString::stringToFloat(vecteur[i]);
        }

    }

}
/***
*\fn void ParserString::vecteurStringTofloatArray(std::vector<std::string> vecteur, float[] arr)
*\brief add float in a vector from a vector of string
*\param string vector and a float vector
*\return nothing
*
*use stringToFloat
*/
void UtilsVector::vecteurStringTofloatVector(std::vector<std::string> vecteurString,std::vector<float>* vecteurFloat){
    for(int i = 0; i< (int)vecteurString.size(); i++)
    {

        if (vecteurString[i] == "NULL")
            (*vecteurFloat).push_back(0.0) ;
        else
        {
            (*vecteurFloat).push_back(ParserString::stringToFloat(vecteurString[i]));
        }
    }
}

/***
*\fn void ParserString::vecteurofVecteurStringTofloatArray(std::vector<std::vector<std::string> > vecteur, float[] arr)
*\brief add float in a array from a vector of string
*\param string vector and a float array
*\return nothing
*
*use stringToFloat
*/
void UtilsVector::vecteurofVecteurStringTofloatArray(std::vector<std::vector<std::string> > vecteur, float arr[101][101], int valeurNull)
{
    for(int i = 0; i< (int)vecteur.size(); i++)
        UtilsVector::vecteurStringTofloatArray(vecteur[i], arr[i], valeurNull);
}

/***
*\fn UtilsVector::countValueInSquareVector(float value, std::vector<std::vector<float> > matrice)
*\brief count the number of a value in a matrice
*\param value float
*\param matrice of float
*\return integer (number of value)
*/
int UtilsVector::countValueInSquareVector(float value, std::vector<std::vector<float> > matrice)
{
    int compteur(0);
    for (int i = 0; i< (int) matrice.size(); i++)
        for (int j = 0; j < (int) matrice.size(); j++)
            if (matrice[i][j] == value)
                compteur++;
    return compteur;
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> > vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printFloatVector(std::vector<std::vector<float> > vecteur)
{
    for (int x = 0; x< (int) vecteur.size(); x++)
    {
        for (int y = 0; y< (int) vecteur[x].size(); y++)
        {
            std::cout << vecteur[x][y] <<  " ";
        }
        std::cout << std::endl;
    }
}

/*!
* \fn float UtilsVector::getMin(std::vector<std::vector<float> > vecteur)
* \brief get the minimal value from a vector of float vector
* \param vector of float vector
* \return float
*/
float UtilsVector::getMin(std::vector<std::vector<float> > vecteur)
{
    float minimun = vecteur[0][0];
     for (int x = 0; x< (int) vecteur.size(); x++)
        for (int y = 0; y< (int) vecteur[x].size(); y++)
            if (vecteur[x][y] < minimun) minimun = vecteur[x][y];
      return minimun;
}

/*!
* \fn float UtilsVector::getMin(std::vector<std::vector<float> > vecteur, float valeurIgnore)
* \brief  get the minimal value from a vector of float vector but we pass over a value
* \param vector of float vector
* \param float value of the value ignore
* \return float
*/
float UtilsVector::getMin(std::vector<std::vector<float> > vecteur, float valeurIgnore)
{
    float minimun = vecteur[0][0];
     for (int x = 0; x< (int) vecteur.size(); x++)
        for (int y = 0; y< (int) vecteur[x].size(); y++)
            if (vecteur[x][y] < minimun && vecteur[x][y] != valeurIgnore)
            {
              minimun = vecteur[x][y];
            }
      return minimun;
}


/*!
* \fn float UtilsVector::getMax(std::vector<std::vector<float> > vecteur)
* \brief  get the maximal value from a vector of float vector
* \param vector of float vector
* \return float
*/
float UtilsVector::getMax(std::vector<std::vector<float> > vecteur)
{
    float maximum = 0;
     for (int x = 0; x< (int) vecteur.size(); x++)
        for (int y = 0; y< (int) vecteur[x].size(); y++)
            if (vecteur[x][y] > maximum)
              maximum = vecteur[x][y];
      return maximum;
}

/*!
* \fn float UtilsVector::getax(std::vector<std::vector<float> > vecteur, float valeurIgnore)
* \brief  get the maximal value from a vector of float vector but we pass over a value
* \param vector of float vector
* \param float value of the value ignore
* \return float
*/
float UtilsVector::getMax(std::vector<std::vector<float> > vecteur,float valeurIgnore )
{
    float maximum = 0;
     for (int x = 0; x< (int) vecteur.size(); x++)
        for (int y = 0; y< (int) vecteur[x].size(); y++)
            if (vecteur[x][y] > maximum && vecteur[x][y] != valeurIgnore)
            {
              maximum = vecteur[x][y];
            }

      return maximum;
}

UtilsVector::~UtilsVector()
{
    //dtor
}
