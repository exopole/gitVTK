#include "UtilsVector.h"

UtilsVector::UtilsVector()
{
    //ctor
}




/**
*\fn void UtilsVector::initVector(std::vector< std::vector<bool> > &v,bool value, int size )
*\brief initialize a boolean vector with a value (false or true)
*\param vecteur 2D of boolean
*\param true or false
*\param size of the vector
*/
void UtilsVector::initVector(std::vector< std::vector<bool> >* v,bool value, int size ){
    std::vector<bool> tmp;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            tmp.push_back(value);
        }
        v->push_back(tmp);
        tmp.clear();
    }
}


/**
*\fn void UtilsVector::initVector(std::vector< std::vector<float> > &v,bool value, int size )
*\brief initialize a float vector with a value 
*\param vecteur 2D of float
*\param value
*\param size of the vector
*/
void UtilsVector::initVector(std::vector< std::vector<float> > *v, float value , int size ){
    std::vector<float> tmp;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
            tmp.push_back(value);

        v->push_back(tmp);
        tmp.clear();
    }
}


/**
*\fn void UtilsVector::initVector(std::vector< std::vector<float> > &v,bool value, int size )
*\brief initialize a float vector with a value 
*\param vecteur 2D of float
*\param value
*\param size of the vector
*/
std::vector< std::vector<float> > UtilsVector::initVector(  float value , int size ){
    std::vector< std::vector<float> > v;
    std::vector<float> tmp;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
            tmp.push_back(value);

        v.push_back(tmp);
        tmp.clear();
    }
    return v;
}

/**
*\fn void UtilsVector::initVector(std::vector< std::vector<bool> > &v,bool value, int size )
*\brief initialize a Point vector 
*\param vecteur 2D of Point null
*\param size of the vector
*/
void UtilsVector::initVector(std::vector< std::vector<Point> > *v, int size ){
    std::vector<Point> tmp;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            tmp.push_back(Point());
        }
        v->push_back(tmp);
        tmp.clear();
    }
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
        std::cout << (*vectorResult)[i] + " " ;
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
void UtilsVector::vecteurStringTofloatArray(std::vector<std::string>* vecteur, float arr[101], float valeurNull)
{
    for(int i = 0; i< (int)vecteur->size(); i++)
    {

        if (vecteur->at(i) == "NULL")
            arr[i] =valeurNull;
        else
        {
            arr[i]  = ParserString::stringToFloat(vecteur->at(i));
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
void UtilsVector::vecteurStringTofloatVector(std::vector<std::string>* vecteurString,std::vector<float>* vecteurFloat){
    for(int i = 0; i< (int)vecteurString->size(); i++)
    {

        if (vecteurString->at(i) == "NULL")
            (*vecteurFloat).push_back(0.0) ;
        else
        {
            (*vecteurFloat).push_back(ParserString::stringToFloat(vecteurString->at(i)));
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
void UtilsVector::vecteurofVecteurStringTofloatArray(std::vector<std::vector<std::string> >* vecteur, float arr[101][101], int valeurNull)
{
    for(int i = 0; i< (int)vecteur->size(); i++)
        UtilsVector::vecteurStringTofloatArray(&(vecteur->at(i)), arr[i], valeurNull);
}

/***
*\fn UtilsVector::countValueInSquareVector(float value, std::vector<std::vector<float> > matrice)
*\brief count the number of a value in a matrice
*\param value float
*\param matrice of float
*\return integer (number of value)
*/
int UtilsVector::countValueInSquareVector(float value, std::vector<std::vector<float> >* matrice)
{
    int compteur(0);
    for (int i = 0; i< (int) matrice->size(); i++)
        for (int j = 0; j < (int) matrice->at(i).size(); j++)
            if (matrice->at(i)[j] == value)
                compteur++;
    return compteur;
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> >* vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<float> >* vecteur)
{
    for (int x = 0; x< (int) vecteur->size(); x++)
    {
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
        {
            std::cout << vecteur->at(x)[y] << " ";
        }
        std::cout << std::endl;
    }
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> > vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<float> > vecteur)
{
    std::cout << "coucou" << std::endl;
    for (int x = 0; x< (int) vecteur.size(); x++)
    {
        for (int y = 0; y< (int) vecteur[x].size(); y++)
        {
            std::cout << vecteur[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> >* vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<float >* vecteur)
{
    for (int x = 0; x< (int) vecteur->size(); x++)
    {

        std::cout << vecteur->at(x) << " ";

    }
    std::cout << std::endl;
}
/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> > vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<float > vecteur)
{
    for (int x = 0; x< (int) vecteur.size(); x++)
    {

        std::cout << vecteur[x] << " ";

    }
    std::cout << std::endl;
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> >* vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<bool> >* vecteur)
{
    for (int x = 0; x< (int) vecteur->size(); x++)
    {
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
        {
            if (vecteur->at(x)[y])
            {
                std::cout << 1 << " ";
            }
            else 
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}
/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> > vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<bool> > vecteur)
{
    for (int x = 0; x< (int) vecteur.size(); x++)
    {
        for (int y = 0; y< (int) vecteur[x].size(); y++)
        {
            if (vecteur[x][y])
            {
                std::cout << 1 << " ";
            }
            else 
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<Point> >* vecteur)
* \param vecteur of Point vector
* \brief print all the data from a vector of Point vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<Point> >* vecteur, int type)
{
    for (int x = 0; x< (int) vecteur->size(); x++)
    {
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
        {
            if (type == 1)
            {
                if (vecteur->at(x)[y].isNull())
                    std::cout << "Null ";
                else 
                    std::cout << vecteur->at(x)[y].toString();
            }
            else
                if (vecteur->at(x)[y].isNull())
                    std::cout << 0;
                else 
                    std::cout << 1;            

        }
        std::cout << std::endl;
    }
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<Point> > vecteur)
* \param vecteur of Point vector
* \brief print all the data from a vector of Point vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<Point> > vecteur, int type)
{
    for (int x = 0; x< (int) vecteur.size(); x++)
    {
        for (int y = 0; y< (int) vecteur[x].size(); y++)
        {
            if (type == 1)
            {
                if (vecteur[x][y].isNull())
                    std::cout << "Null ";
                else 
                    std::cout << vecteur[x][y].toString();
            }
            else
                if (vecteur[x][y].isNull())
                    std::cout << 0;
                else 
                    std::cout << 1;            

        }
        std::cout << std::endl;
    }
}

/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<Point> > vecteur)
* \param vecteur of Point vector
* \brief print all the data from a vector of Point vector
* \
*/
void UtilsVector::printVectorNonNull(std::vector<std::vector<Point> > vecteur)
{
    for (int x = 0; x< (int) vecteur.size(); x++)
    {
        for (int y = 0; y< (int) vecteur[x].size(); y++)
            if (! vecteur[x][y].isNull())
                std::cout << "[" << vecteur[x][y].getX() << ", " << vecteur[x][y].getY()  << ", " << vecteur[x][y].getZ() << "]" << std::endl;
    }
}


/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<Point> >* vecteur)
* \param vecteur of Point vector
* \brief print all the data from a vector of Point vector
* \
*/
void UtilsVector::printVector(std::vector<Point> * vecteur)
{
    for (int x = 0; x< (int) vecteur->size(); x++)

        std::cout << vecteur->at(x).toString()<< std::endl;
}


/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> >* vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<float> >* vecteur, float valeurNull)
{
    for (int x = 0; x< (int) vecteur->size(); x++)
    {
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
        {
            if (vecteur->at(x)[y] == valeurNull)
            {
                std::cout << 0;
            }
            else 
                std::cout << 1;
        }
        std::cout << std::endl;
    }
}
/*!
* \fn void UtilsVector::printFloatVector(std::vector<std::vector<float> > vecteur)
* \param vecteur of float vector
* \brief print all the data from a vector of float vector
* \
*/
void UtilsVector::printVector(std::vector<std::vector<float> > vecteur, float valeurNull)
{
    for (int x = 0; x< (int) vecteur.size(); x++)
    {
        for (int y = 0; y< (int) vecteur[x].size(); y++)
        {
            if (vecteur[x][y] == valeurNull)
            {
                std::cout << 0;
            }
            else 
                std::cout << 1;
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
float UtilsVector::getMin(std::vector<std::vector<float> >* vecteur)
{
    float minimun = vecteur->at(0)[0];
     for (int x = 0; x< (int) vecteur->size(); x++)
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
            if (vecteur->at(x)[y] < minimun) minimun = vecteur->at(x)[y];
      return minimun;
}



/*!
* \fn float UtilsVector::getMin(std::vector<std::vector<float> > vecteur, float valeurIgnore)
* \brief  get the minimal value from a vector of float vector but we pass over a value
* \param vector of float vector
* \param float value of the value ignore
* \return float
*/
float UtilsVector::getMin(std::vector<std::vector<float> >* vecteur, float valeurIgnore)
{
    float minimun = vecteur->at(0)[0];
     for (int x = 0; x< (int) vecteur->size(); x++)
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
            if (vecteur->at(x)[y] < minimun && vecteur->at(x)[y] != valeurIgnore)
            {
              minimun = vecteur->at(x)[y];
            }
      return minimun;
}


/*!
* \fn float UtilsVector::getMax(std::vector<std::vector<float> > vecteur)
* \brief  get the maximal value from a vector of float vector
* \param vector of float vector
* \return float
*/
float UtilsVector::getMax(std::vector<std::vector<float> > *vecteur)
{
    float maximum = 0;
     for (int x = 0; x< (int) vecteur->size(); x++)
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
            if (vecteur->at(x)[y] > maximum)
              maximum = vecteur->at(x)[y];
      return maximum;
}

/*!
* \fn float UtilsVector::getax(std::vector<std::vector<float> > vecteur, float valeurIgnore)
* \brief  get the maximal value from a vector of float vector but we pass over a value
* \param vector of float vector
* \param float value of the value ignore
* \return float
*/
float UtilsVector::getMax(std::vector<std::vector<float> >* vecteur,float valeurIgnore )
{
    float maximum = 0;
     for (int x = 0; x< (int) vecteur->size(); x++)
        for (int y = 0; y< (int) vecteur->at(x).size(); y++)
            if (vecteur->at(x)[y] > maximum && vecteur->at(x)[y] != valeurIgnore)
            {
              maximum = vecteur->at(x)[y];
            }

      return maximum;
}

/**
*\fn bool UtilsVector::checkValueOutline(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief check if a value around a value in a matrice is not equal to a specific value
*\param vector 2D of float
*\param value to search
*\return float value
*/
bool UtilsVector::checkValueOutline(std::vector<std::vector<float> >* matrice, int x, int y,  float value){
    
    
    if (x > 0 && x < matrice->size()-1 && y < matrice->at(x).size()-1 && y > 0)
        return matrice->at(x-1)[y-1] == value || matrice->at(x-1)[y] == value || matrice->at(x-1)[y+1] == value 
            || matrice->at(x)[y-1] == value || matrice->at(x)[y] == value || matrice->at(x)[y+1] == value 
            || matrice->at(x+1)[y-1] == value || matrice->at(x+1)[y] == value || matrice->at(x+1)[y+1] == value;
    else 
        return true;
}

/**
*\fn bool UtilsVector::checkValueOutline(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief check if a value around a value in a matrice is not equal to a specific value
*\param vector 2D of float
*\param value to search
*\return float value
*/
bool UtilsVector::checkValueOutline(std::vector<std::vector<Point> > *matrice, int x, int y){
    
    bool trouver(false), fin(false);
    int ptX(0), ptY(0);

    if (x == 0)
        ptX = 0;
    else
        ptX = x-1;

    if (y == 0)
        ptY = 0;
    else
        ptY = y-1;

    do{
        if (matrice->at(ptX)[ptY].isNull()){
            trouver = true;
        }
        else{
            if (ptY < matrice->at(ptX).size() - 1 || ptY < y + 2  ) 
                ptY ++;
            else if (ptX < matrice->at(ptX).size() -1 || ptX < x + 2)
            {
                ptX++;
                if (y != 0)
                    ptY = y-1;
                else 
                    ptY = 0;
            }
            else
                fin = true;

        }
    }
    while (! trouver && ! fin);

    return trouver;
}



/**
*\fn float UtilsVector::average(std::vector<std::vector<float> > *matrice, 
                                    int x, int y, float valeurNull)
*\brief calcul of the average value in a point 
*\param pointer to a 2D vector float
*\param float => null value
*\param float value => null
*\retuen float => average 
*/
float UtilsVector::average(std::vector<std::vector<float> > *matrice, 
                                    int x, int y, float valeurNull){
    int count(0);
    float sum(0);
    int x2(x-1), y2(y);

    while(x2 >= 0 && matrice->at(x2)[y] == valeurNull){
        x2--;
    }
    
    if (x2 >= 0)
    {
        sum+=matrice->at(x2)[y];
        count++;
    }

    x2 = x+1;
    while(x2 < matrice->size() && matrice->at(x2)[y] == valeurNull){
        x2++;
    }
    
    if (x2 < matrice->size())
    {
        sum+=matrice->at(x2)[y];
        count++;
    }

    y2 = y-1;
    while(y2 >= 0 && matrice->at(x)[y2] == valeurNull){
        y2--;
    }
    
    if (y2 >= 0)
    {
        sum+=matrice->at(x)[y2];
        count++;
    }

    y2=y+1;
    while(y2 < matrice->at(x).size() && matrice->at(x)[y2] == valeurNull){
        y2++;
    }
    
    if (y2 < matrice->at(x).size())
    {
        sum+=matrice->at(x)[y2];
        count++;
    }

    return sum/count;

}

/**
*\fn int UtilsVector::countConsecutiveValue(std::vector<std::vector<float> > *matrice, int x, int y,  float valeurNull){
*\brief account all consecutive value non null on a line
*\
*/

int UtilsVector::countConsecutiveValue(std::vector<std::vector<float> > *matrice, int x, int y,  float valeurNull){
    int count(0);
    do{
        count++;
        y++;
    }
    while(y < matrice->at(x).size() && matrice->at(x)[y] != valeurNull);
    return count;

}


/**
*\fn std::vector<Point> UtilsVector::findPointWithLessDistance(std::vector<std::vector<float> > *matrice1, std::vector<std::vector<float> > *matrice2, float valeurIgnore)
*\brief allow us to find the two points with the lesser distance between 2 matrice
*\param 2 pointeur of vector 2D float
*\param float=> null value
*\return vector of the 2 points which have the lesser distance
*/
std::vector<Point> UtilsVector::findPointWithLessDistance(std::vector<std::vector<float> > *matrice1, std::vector<std::vector<float> > *matrice2, float valeurIgnore){
    float distanceMin = valeurIgnore;
    float distanceTmp;
    Point P1;
    Point P2;
    Point resultP1;
    Point resultP2;
    for (int x = 0; x < matrice1->size(); x++)
    {
        for (int y = 0; y < matrice1->at(x).size(); y++)
        {
            if (matrice1->at(x)[y] != valeurIgnore)
            {
                if (distanceMin == valeurIgnore)
                {
                    resultP1.setCoordonne(x, y, matrice1->at(x)[y]);
                    resultP2.copy(UtilsVector::findPointWithLessDistance(&resultP1, matrice2, valeurIgnore)) ;
                    distanceMin = UtilsGeometry::distanceBetween3DPoint(&resultP1, &resultP2) ;
                }
                else{
                    P1.setCoordonne(x, y, matrice1->at(x)[y]);
                    P2.copy(UtilsVector::findPointWithLessDistance(&P1, matrice2, valeurIgnore)) ;
                    distanceTmp = UtilsGeometry::distanceBetween3DPoint(&P1, &P2) ;
                    if (distanceTmp < distanceMin)
                    {
                        distanceMin = distanceTmp;
                        resultP1.setCoordonne(x, y, matrice1->at(x)[y]);
                        resultP2.copy(P2);
                    }
                }
            }
        }
    }
    std::vector<Point> v ;
    v.push_back(resultP1);
    v.push_back(resultP2);
    
    return  v;
}

/**
*\fn std::vector<Point> UtilsVector::findPointWithLessDistance(Point* P1,std::vector<std::vector<float> > *matrice, float valeurIgnore)
*\brief allow us to find the points with the lesser distance with the point put in argument
*\param 1 point
*\param 1 pointeur of vector 2D float
*\param float=> null value
*\return vector of the 2 points which have the lesser distance
*/
Point UtilsVector::findPointWithLessDistance(Point* P1, std::vector<std::vector<float> > *matrice, float valeurIgnore){
    float distanceMin = valeurIgnore;
    float distanceTmp;
    Point result;
    Point P2;
    for (int x = 0; x < matrice->size(); x++)
    {
        for (int y = 0; y < matrice->at(x).size(); y++)
        {
            if (matrice->at(x)[y] != valeurIgnore)
            {
                if (distanceMin == valeurIgnore)
                {
                    result.setCoordonne(x, y, matrice->at(x)[y]);
                    distanceMin = UtilsGeometry::distanceBetween3DPoint(P1, &result);
                }
                else{
                    P2.setCoordonne(x, y, matrice->at(x)[y]);
                    distanceTmp = UtilsGeometry::distanceBetween3DPoint(P1, &P2) ;
                    if(distanceTmp < distanceMin){
                        distanceMin = distanceTmp;
                        result.setCoordonne(x, y, matrice->at(x)[y]);
                    }

                }
            }
        }
    }
    return result;
}






UtilsVector::~UtilsVector()
{
    //dtor
}
