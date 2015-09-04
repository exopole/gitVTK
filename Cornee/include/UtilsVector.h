#ifndef UTILSVECTOR_H
#define UTILSVECTOR_H

#include "iostream"
#include "ParserString.h"
#include "Point.h"
#include "UtilsGeometry.h"


class UtilsVector
{
    public:
        UtilsVector();
        virtual ~UtilsVector();

        
        static void initVector(std::vector< std::vector <bool>  > * v, bool value, int size );
        static void initVector(std::vector< std::vector <float> > * v, float value, int size );
        static void initVector(std::vector< std::vector <Point> > * v, int size );
        ///\brief print all element from a vector of string
        static void stringVectorToString(std::vector <std::string>* vectorResult);
        static void stringVectorToString(std::vector <std::string> vectorResult);
        ///\brief print all element from a vector of vector of string
        static void vectorOfStringVectorToString(std::vector<std::vector <std::string> >* vectorResult);        
        static void printVector(std::vector<std::vector<float> >* vecteur);
        static void printVector(std::vector<std::vector<float> > vecteur);
        static void printVector(std::vector<std::vector<bool> >* vecteur);
        static void printVector(std::vector<std::vector<bool> > vecteur);
        static void printVector(std::vector<std::vector<float> > *vecteur, float valeurNull);
        static void printVector(std::vector<std::vector<float> > vecteur, float valeurNull);
        static void printVector(std::vector<std::vector<Point> > *vecteur, int type);
        static void printVector(std::vector<std::vector<Point> > vecteur, int type);
        static void printVector(std::vector<float > *vecteur);
        static void printVector(std::vector<float > vecteur);
        static void printVector(std::vector<Point> * vecteur);
        ///\brief  return a float vector from a string vector
        static void vecteurStringTofloatVector(std::vector<std::string>* vecteurString,std::vector<float>* vecteurFloat);
        static void vecteurStringTofloatArray(std::vector<std::string> *vecteur, float*  arr, float valeurNull );
        static void vecteurofVecteurStringTofloatArray(std::vector<std::vector<std::string> >* vecteur, float arr[][101], int valeurNull);

        
        static int countConsecutiveValue(std::vector<std::vector<float> > *matrice, int x, int y,  float valeurNull);
        ///\brief return an integer, number of a value in a matrice
        static int countValueInSquareVector(float value, std::vector<std::vector<float> >* matrice);


        ///\brief return a float
        static float getMin(std::vector<std::vector<float> > *matrice);
        static float getMax(std::vector<std::vector<float> > *matrice);
        static float getMin(std::vector<std::vector<float> > *matrice, float valeurIgnore);
        static float getMax(std::vector<std::vector<float> > *matrice, float valeurIgnore);
        static float average(std::vector<std::vector<float> > *matrice, int x, int y, float valeurNull);

        static bool checkValueOutline(std::vector<std::vector<float> > *matrice, int x, int y,  float value);
        static bool checkValueOutline(std::vector<std::vector<Point> >* matrice, int x, int y);
        
        static std::vector< Point> findPointWithLessDistance(std::vector<std::vector<float> > *matrice1, std::vector<std::vector<float> > *matrice2, float valeurIgnore);

        static Point findPointWithLessDistance(Point* P1, std::vector<std::vector<float> > *matrice, float valeurIgnore);





    protected:
    private:
};

#endif // UTILSVECTOR_H
