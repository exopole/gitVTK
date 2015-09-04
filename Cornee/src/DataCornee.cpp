#include "DataCornee.h"

/**
*\fn DataCornee::DataCornee(std::string name, float data[SIZEMAX][SIZEMAX])
*\brief constructeur
*\param name of the data
*\param float matrice 2D
*/

DataCornee::DataCornee(std::string name, float data[SIZEMAX][SIZEMAX])
{
    m_name = name;
    DataCornee::copieTableau(data);
}

/**
*\fn std::string DataCornee::getName()
*\brief name of the data
*\return the name (string)
*/
std::string DataCornee::getName()
{
    return m_name;
}

/**
*\fn DataCornee::setData(float data[SIZEMAX][SIZEMAX])
*\brief copie the data in a matrice 2D of float
*\param matrice 2d of float
*/
void DataCornee::setData(float data[SIZEMAX][SIZEMAX]){

    DataCornee::copieTableau(data);
}

/**
*\fn DataCornee::getData(float data[SIZEMAX][SIZEMAX])
*\brief copie the data in a matrice 2D of float
*\param matrice 2d of float
*/
std::vector<std::vector<float> > DataCornee::getData(){

    std::vector<std::vector<float> > dest;
    std::vector<float> line;
    for(int i = 0; i< SIZEMAX; i++)
    {
        for(int j = 0; j< SIZEMAX; j++){
            //std::cout << i << "," << j << std::endl;
            line.push_back(DataCornee::getData(i,j));
        }
        dest.push_back(line);
        line.clear();
    }

    return dest;
}

/**
*\fn int DataCornee::getData(int x, int y)
*\brief get a value from the data
*\param coord x and y of the value
*\return a value
*/
float DataCornee::getData(int x, int y)
{
    return m_data[x][y];
}

/**
*\fn void DataCornee::copieTableau(float data[SIZEMAX][SIZEMAX])
*\brief copie all the data in a matrice 2D of float with a size = SIZEMAX
*\param matrice 2D of float
*/
void DataCornee::copieTableau(float data[SIZEMAX][SIZEMAX])
{
    for (int i = 0; i < SIZEMAX ; i++)
        for (int j =0; j < SIZEMAX; j++)
            m_data[i][j] = data[i][j];
}

/**
*\fn DataCornee::dataToString()
*\brief print all data of the cornea
*/
void DataCornee::dataToString()
{
    for (int i = 0; i < SIZEMAX ; i++){
        for (int j =0; j < SIZEMAX; j++)
            std::cout << m_data[i][j] << " " ;
        std::cout << std::endl;
    }
}


DataCornee::~DataCornee()
{
    //dtor
}
