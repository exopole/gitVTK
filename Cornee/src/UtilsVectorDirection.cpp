#include "UtilsVectorDirection.h"


UtilsVectorDirection::UtilsVectorDirection(){}

/**
*\fn void UtilsVector::findDirection(std::vector<std::vector<float> > *matrice, 
                                    int x, int y,
                                    float valeurNull)
*\brief find the next position 
*\param vector 2D float pointeur 
*\param int pointer => coordonate x y
*\param float null value
*/
void UtilsVectorDirection::find(std::vector<std::vector<float> > *matrice, 
                                    int &x, int &y,
                                    float valeurNull){
    if (x > 0 && matrice->at(x-1)[y]!=valeurNull){
        x = x-1;
    }
    else if (y > 0 && matrice->at(x)[y-1]!=valeurNull){
        y = y-1;
    }
    else if (y < matrice->at(x).size()-1 && matrice->at(x)[y+1]!=valeurNull){
        y = y+1;
    }
    else if (x < matrice->size()-1 && matrice->at(x+1)[y]!=valeurNull ){
        x = x+1;
    }
}




/**
*\fn int UtilsVector::findDirection(std::vector<std::vector<float> > *matrice, 
                                    int x, int y,
                                    float valeurNull)
*\brief find the next position 
*\param vector 2D float pointeur 
*\param int pointer => coordonate x y
*\param float null value
*/
void UtilsVectorDirection::findNext(std::vector<std::vector<float> > *matrice, 
                                    int &xPrec, int &yPrec,
                                    int &x, int &y,
                                    float valeurNull){
    if (x > 0 && xPrec != x-1 && matrice->at(x-1)[y]!=valeurNull){
        xPrec = x;
        x = x-1;
    }
    else if (y > 0  && yPrec != y-1 && matrice->at(x)[y-1]!=valeurNull){
        yPrec = y;
        y = y-1;
    }
    else if (y < matrice->at(x).size()-1 && yPrec != y+1 && matrice->at(x)[y+1]!=valeurNull){
        yPrec = y;
        y = y+1;
    }
    else if (x < matrice->size()-1 && xPrec != x+1 && matrice->at(x+1)[y]!=valeurNull ){
        xPrec = x;
        x = x+1;
    }
}

bool UtilsVectorDirection::next(std::vector<std::vector<float> > *matrice, 
                                    float &x, float &y,
                                    int direction,
                                    float valeurNull){
    if (direction == -1 && x > 0 && matrice->at(x-1)[y]!=valeurNull){
        x--;
    }
    else if (direction == -2 && y > 0 && matrice->at(x)[y-1]!=valeurNull){
        y--;
    }
    else if (direction == 2 && y < matrice->at(x).size()-1 && matrice->at(x)[y+1]!=valeurNull){
        y++;
    }
    else if (direction == 1 && x < matrice->size()-1 && matrice->at(x+1)[y]!=valeurNull ){
        x++;
    }
    else
        return false;

    return true;
}


int UtilsVectorDirection::findType(std::vector<std::vector<float> > *matrice, 
                                    float x, float y,
                                    float valeurNull)
{
    if (x > 0 && matrice->at(x-1)[y]!=valeurNull){
        return -1;
    }
    else if (y > 0 && matrice->at(x)[y-1]!=valeurNull){
        return -2;
    }
    else if (y < matrice->at(x).size()-1 && matrice->at(x)[y+1]!=valeurNull){
        return 2;
    }
    else if (x < matrice->size()-1 && matrice->at(x+1)[y]!=valeurNull ){
        return 1;
    }
}

int UtilsVectorDirection::findType(std::vector<std::vector<float> > *matrice, 
                                    float x, float y, int direction,
                                    float valeurNull)
{
    if (direction != -1 && x > 0 && matrice->at(x-1)[y]!=valeurNull){
        return -1;
    }
    else if (direction != -2 && y > 0 && matrice->at(x)[y-1]!=valeurNull){
        return -2;
    }
    else if (direction != 1 && y < matrice->at(x).size()-1 && matrice->at(x)[y+1]!=valeurNull){
        return 2;
    }
    else if (direction != 2 && x < matrice->size()-1 && matrice->at(x+1)[y]!=valeurNull ){
        return 1;
    }

}

/**
*\fn int UtilsVectorDirection::numberOfDirection(std::vector<std::vector<float> > *matrice, 
                                    int x, int y,
                                    float valeurNull)
*\brief account all possible directions from a position
*\param vector 2D float pointeur 
*\param int => coordonate x y
*\param float null value
*/
int UtilsVectorDirection::numberOf(std::vector<std::vector<float> > *matrice, 
                                    int x, int y,
                                    float valeurNull){
    int count(0);
    if (x > 0 && matrice->at(x-1)[y]!=valeurNull)
        count++;
    if (y > 0 && matrice->at(x)[y-1]!=valeurNull)
        count++;
    if (y < matrice->at(x).size()-1 && matrice->at(x)[y+1]!=valeurNull)
        count++;
    if (x < matrice->size()-1 && matrice->at(x+1)[y]!=valeurNull )
    {
        count++;
    }
    return count;
}


/**
*\fn int UtilsVectorDirection::findDirection(std::vector<std::vector<float> > *matrice, 
                                    int x, int y,
                                    float valeurNull)
*\brief find the next position 
*\param vector 2D float pointeur 
*\param int pointer => coordonate x y
*\param float null value
*/
int UtilsVectorDirection::findAndType(std::vector<std::vector<float> > *matrice, 
                                    int &x, int &y,
                                    float valeurNull){

    if (x > 0 && matrice->at(x-1)[y]!=valeurNull){
        x = x-1;
        return 1;
    }
    else if (y > 0 && matrice->at(x)[y-1]!=valeurNull){
        y = y-1;
        return -2;
    }
    else if (y < matrice->at(x).size()-1 && matrice->at(x)[y+1]!=valeurNull){
        y = y+1;
        return 2;
    }
    else if (x < matrice->size()-1 && matrice->at(x+1)[y]!=valeurNull ){
        x = x+1;
        return 1;
    }
}


/**
*\fn int UtilsVectorDirection::findDirection(std::vector<std::vector<float> > *matrice, 
                                    int x, int y,
                                    float valeurNull)
*\brief find the next position 
*\param vector 2D float pointeur 
*\param int pointer => coordonate x y
*\param float null value
*/
int UtilsVectorDirection::findNextAndType(std::vector<std::vector<float> > *matrice, 
                                    int &xPrec, int &yPrec,
                                    int &x, int &y,
                                    float valeurNull){
    if (x > 0 && xPrec != x-1 && matrice->at(x-1)[y]!=valeurNull){
        xPrec = x;
        yPrec = y;
        x = x-1;
       // std::cout << 1 << std::endl;
        return -1;
    }
    else if (y > 0  && yPrec != y-1 && matrice->at(x)[y-1]!=valeurNull){
        xPrec = x;
        yPrec = y;
        y = y-1;
       // std::cout << 2 << std::endl;
        return -2;
    }
    else if (y < matrice->at(x).size()-1 && yPrec != y+1 && matrice->at(x)[y+1]!=valeurNull){
        xPrec = x;
        yPrec = y;
        y = y+1;
       // std::cout << 3 << std::endl;
        return 2;
    }
    else if (x < matrice->size()-1 && xPrec != x+1 && matrice->at(x+1)[y]!=valeurNull ){
        xPrec = x;
        yPrec = y;
        x = x+1;
     //  std::cout << 4 << std::endl;
        return 1;
    }
}

/**
*\fn int UtilsVectorDirection::findDirection(std::vector<std::vector<float> > *matrice, 
                                    int x, int y,
                                    float valeurNull)
*\brief find the next position 
*\param vector 2D float pointeur 
*\param int pointer => coordonate x y
*\param float null value
*/
int UtilsVectorDirection::findNextAndType(std::vector<std::vector<float> > *matrice, 
                                    float &x, float &y, int direction,
                                    float valeurNull){
    if (direction != -1 && x > 0 && matrice->at(x-1)[y]!=valeurNull){
        x = x-1;
        return -1;
    }
    else if (direction != -2 && y > 0  && matrice->at(x)[y-1]!=valeurNull){
        y = y-1;
        return -2;
    }
    else if (direction != 2 && y < matrice->at(x).size()-1  && matrice->at(x)[y+1]!=valeurNull){
        y = y+1;
        return 2;
    }
    else if (direction != 1 && x < matrice->size()-1  && matrice->at(x+1)[y]!=valeurNull ){
        x = x+1;
        return 1;
    }
    else
        return 0;
}

UtilsVectorDirection::~UtilsVectorDirection(){}