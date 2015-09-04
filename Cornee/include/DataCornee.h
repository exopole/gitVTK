#ifndef DATACORNEE_H
#define DATACORNEE_H


#include "iostream"
#include "string"
#include "UtilsVector.h"
/**
*\file DataCornee.h
*\brief Objet of cornee data
*\author Alexandre.N
*\date 26/05/15
*
*Objet to stock name and data from cornea
*/



const int SIZEMAX(101);
class DataCornee
{

    public:
        DataCornee(std::string name, float data[SIZEMAX][SIZEMAX]);
        virtual ~DataCornee();

        std::string getName();
        std::vector<std::vector<float> > getData();
        float getData(int x, int y);
        void setData(float data[SIZEMAX][SIZEMAX]);
        void dataToString();
        bool testDataVide();

    protected:
    private:
        int m_size;
        std::string m_name;
        float m_data[SIZEMAX][SIZEMAX];
        void copieTableau(float data[SIZEMAX][SIZEMAX]);
};

#endif // DATACORNEE_H
