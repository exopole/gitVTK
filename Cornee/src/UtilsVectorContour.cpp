#include "UtilsVectorContour.h"


UtilsVectorContour::UtilsVectorContour(){
}

/**
*\fn void UtilsVector::eraseArmContour(std::vector<std::vector<float> > *matrice, float valeurNull )
*\brief erase all arms 
*\param vector 2D float pointeur 
*\param float null value
*/
void UtilsVectorContour::eraseArmContour(std::vector<std::vector<float> > *matrice, float valeurNull ){
    int x2 = 0;
    int y2 = 0;
    for (int x = 0; x < matrice->size(); x++)
    {
        for (int y = 0; y < matrice->at(x).size(); y++)
        {
            if (matrice->at(x)[y] != valeurNull)
            {
                if (UtilsVectorDirection::numberOf(matrice, x, y, valeurNull) == 1)
                {
                    x2 = x;
                    y2 = y;
                    do{
                        matrice->at(x2)[y2] = valeurNull;
                        UtilsVectorDirection::find(matrice, x2, y2, valeurNull) ;
                    }
                    while(UtilsVectorDirection::numberOf(matrice, x2, y2, valeurNull) == 1);
                }
            }

        }
    }
}




/**
*\fn void UtilsVector::eraseLine(std::vector<std::vector<float> > *matrice, float valeurNull )
*\brief erase all arms 
*\param vector 2D float pointeur
*\param int number of value non null 
*\param float null value
*/
void UtilsVectorContour::eraseLine(std::vector<std::vector<float> > *matrice, int number, float valeurNull ){
    int count;
    int y2;
    for (int x = 0; x < matrice->size(); x++)
    {
        for (int y = 0; y < matrice->at(x).size(); y++)
        {
            if (matrice->at(x)[y] != valeurNull)
            {
                count = UtilsVector::countConsecutiveValue(matrice, x, y, valeurNull) ;
                if (count < number){
                    y2 = y + count;
                    for (y; y < y2; y++)
                        matrice->at(x)[y] = valeurNull;
                }
                else
                    y += count;
            }
        }
    }
}




/**
*\fn void UtilsVector::fillHoleInMatrice(std::vector<std::vector<float> > *matriceValue, float valeurNull)
*\brief fill all holl in the set of data
*\param pointer to a 2D vector float
*\param float value => null
*/
void UtilsVectorContour::fillHoleInMatrice(std::vector<std::vector<float> > *matriceValue, float valeurNull){
    std::vector<std::vector<float> > matriceTemoin;
    UtilsVector::initVector(&matriceTemoin, 0, matriceValue->size() );
    UtilsVectorContour::bringOutOutsideValue(matriceValue,&matriceTemoin, 0 ,0, valeurNull);
    UtilsVectorContour::bringOutOutsideValue(matriceValue,&matriceTemoin, 0 ,matriceValue->size()-1, valeurNull);
    UtilsVectorContour::bringOutOutsideValue(matriceValue,&matriceTemoin, matriceValue->size()-1 ,0, valeurNull);
    UtilsVectorContour::bringOutOutsideValue(matriceValue,&matriceTemoin, matriceValue->size()-1 ,matriceValue->size()-1, valeurNull);

    for (int x = 0; x < matriceValue->size(); x++)
        for (int y = 0; y < matriceValue->at(x).size(); y++)
            if (matriceTemoin[x][y] == 0 && matriceValue->at(x)[y] == valeurNull)
                matriceValue->at(x)[y] = UtilsVector::average(matriceValue, x, y, valeurNull);
}

/**
*\fn void UtilsVector::fillSurfaceInMatrice(std::vector<std::vector<float> > *matriceValue, float valeurNull)
*\brief fill all holl in the set of data
*\param pointer to a 2D vector float
*\param float value => null
*/
void UtilsVectorContour::fillSurfaceInMatrice(std::vector<std::vector<float> > *matriceValue, float valeurNull){
    std::vector<std::vector<float> > matriceTemoin;
    UtilsVector::initVector(&matriceTemoin, 0, matriceValue->size() );
    UtilsVectorContour::bringOutInsideValue(matriceValue,&matriceTemoin, matriceValue->size()/2 , matriceValue->size()/2, valeurNull);

    for (int x = 0; x < matriceValue->size(); x++)
        for (int y = 0; y < matriceValue->at(x).size(); y++)
            if (matriceTemoin[x][y] == 0 && matriceValue->at(x)[y] != valeurNull)
                matriceValue->at(x)[y] = valeurNull;
}

/**
*\fn void UtilsVector::bringOutOutsideValue(std::vector<std::vector<float> > *matriceValue,std::vector<std::vector<float> > *matriceTemoin,
                                         int x, int y, 
                                         float valeurNull)
*\brief bring out the null value in a matrice not in the data surface
*\param 2 vector 2d pointer of float
*\param 2 int x, y => coordonate
*\param float => null value
*/
void UtilsVectorContour::bringOutOutsideValue(std::vector<std::vector<float> > *matriceValue,std::vector<std::vector<float> > *matriceTemoin,
                                         int x, int y, 
                                         float valeurNull){

    if (x < matriceValue->size() && y < matriceValue->at(x).size() && matriceValue->at(x)[y] == valeurNull && matriceTemoin->at(x)[y]!=1)
    {
        matriceTemoin->at(x)[y] = 1;
        if (x > 0)
        {
            UtilsVectorContour::bringOutOutsideValue(matriceValue,matriceTemoin, x-1 ,y, valeurNull);
        }
         if (y > 0)
        {
            UtilsVectorContour::bringOutOutsideValue(matriceValue,matriceTemoin, x ,y-1, valeurNull);
        }
        UtilsVectorContour::bringOutOutsideValue(matriceValue,matriceTemoin, x+1 ,y, valeurNull);
        UtilsVectorContour::bringOutOutsideValue(matriceValue,matriceTemoin, x ,y+1, valeurNull);
    }

}

/**
*\fn void UtilsVector::bringOutOutsideValue(std::vector<std::vector<float> > *matriceValue,std::vector<std::vector<float> > *matriceTemoin,
                                         int x, int y, 
                                         float valeurNull)
*\brief bring out the null value in a matrice not in the data surface
*\param 2 vector 2d pointer of float
*\param 2 int x, y => coordonate
*\param float => null value
*/
void UtilsVectorContour::bringOutInsideValue(std::vector<std::vector<float> > *matriceValue,std::vector<std::vector<float> > *matriceTemoin,
                                         int x, int y, 
                                         float valeurNull){

    if (x < matriceValue->size() && y < matriceValue->at(x).size() && matriceValue->at(x)[y] != valeurNull && matriceTemoin->at(x)[y]!=1)
    {
        matriceTemoin->at(x)[y] = 1;
        if (x > 0)
        {
            UtilsVectorContour::bringOutInsideValue(matriceValue,matriceTemoin, x-1 ,y, valeurNull);
        }
         if (y > 0)
        {
            UtilsVectorContour::bringOutInsideValue(matriceValue,matriceTemoin, x ,y-1, valeurNull);
        }
        UtilsVectorContour::bringOutInsideValue(matriceValue,matriceTemoin, x+1 ,y, valeurNull);
        UtilsVectorContour::bringOutInsideValue(matriceValue,matriceTemoin, x ,y+1, valeurNull);
    }

}


/**
* \fn int UtilsVector::numberOfFaces(Point *P1, std::vector<float> *matrice)
* \brief count the number of a face from a contour matrice
* \param Point 
* \param matrice contour
*/
int UtilsVectorContour::numberOfFaces(Point *P1, std::vector<std::vector<float> > *matrice, float valeurNull){
    std::vector<float> matriceTmp;
    int x(P1->getX()), y(P1->getY()), x2, y2, direction1, direction2,numberOfFaces(0); 
    x2 = x;
    y2 = y;
    direction1 = UtilsVectorDirection::findAndType(matrice, x2, y2, valeurNull);
  
    do{
        direction2 = UtilsVectorDirection::findNextAndType(matrice, x, y, x2, y2, valeurNull);
        if (direction1 != direction2)
        {
            numberOfFaces++;
            direction1 = direction2;
        }
    }
    while((x2 != P1->getX() || y2 != P1->getY()) );
    return numberOfFaces;

}




/**
*\fn std::vector< std::vector<float> > UtilsVector::getContour(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief extract the outline
*\param vector 2D of float
*\param float value of the Null value
*\return vector 2D of the outline
*/
std::vector< std::vector<float> > UtilsVectorContour::getContour(std::vector<std::vector<float> >* matrice, float valeurIgnore){
    std::vector<std::vector<float> > contour;
    std::vector<float> tmp;

    for (int x = 0; x < matrice->size(); x++)
    {
        for (int y = 0; y < matrice->at(x).size(); y++)
        {
            if (matrice->at(x)[y] != valeurIgnore){
                if (UtilsVector::checkValueOutline(matrice, x, y,  valeurIgnore)){
                    tmp.push_back(matrice->at(x)[y]);
                }
                else{
                    tmp.push_back(valeurIgnore); 
                }
            }
            else{
                tmp.push_back(valeurIgnore);
            }

        }

        contour.push_back(tmp);
        tmp.clear();
    }
    return contour;
}


/**
*\fn std::vector< std::vector<float> > UtilsVector::getContour(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief extract the outline
*\param vector 2D of float
*\param float value of the Null value
*\return vector 2D of the outline
*/
std::vector< std::vector<float> > UtilsVectorContour::getContour(std::vector<std::vector<float> > matrice, float valeurIgnore){
    std::vector<std::vector<float> > contour;
    std::vector<float> tmp;

    for (int x = 0; x < matrice.size(); x++)
    {
        for (int y = 0; y < matrice[x].size(); y++)
        {
            if (matrice[x][y] != valeurIgnore){
                if (UtilsVector::checkValueOutline(&matrice, x, y,  valeurIgnore)){
                    tmp.push_back(matrice[x][y]);
                }
                else{
                    tmp.push_back(valeurIgnore); 
                }
            }
            else{
                tmp.push_back(valeurIgnore);
            }

        }

        contour.push_back(tmp);
        tmp.clear();
    }
    return contour;
}



/**
*\fn std::vector< std::vector<float> > UtilsVector::getContour(std::vector<std::vector<float> > matrice, float valeurIgnore)
*\brief extract the outline
*\param vector 2D of float
*\param float value of the Null value
*\return vector 2D of the outline
*/
std::vector< std::vector<Point> > UtilsVectorContour::getContour(std::vector<std::vector<Point> >* matrice){
    std::vector<std::vector<Point> > contour;
    std::vector<Point> tmp;

    for (int x = 0; x < matrice->size(); x++)
    {
        for (int y = 0; y < matrice->at(x).size(); y++)
        {

            if (! matrice->at(x)[y].isNull())
                if (UtilsVector::checkValueOutline(matrice, x, y))
                    tmp.push_back(matrice->at(x)[y]);
                else
                    tmp.push_back(Point()); 
            else 
                 tmp.push_back(Point());          

        }

        contour.push_back(tmp);
        tmp.clear();
    }
    return contour;
}



UtilsVectorContour::~UtilsVectorContour(){

}