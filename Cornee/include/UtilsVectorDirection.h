#ifndef UTILSVECTORDIRECTION_H
#define UTILSVECTORDIRECTION_H value

#include "UtilsVector.h"


class UtilsVectorDirection
{
public:
	UtilsVectorDirection();
	~UtilsVectorDirection();
    static void find(std::vector<std::vector<float> > *matrice, 
                        int &x, int &y,
                        float valeurNull);
 	static void findNext(std::vector<std::vector<float> > *matrice, 
                        int &xPrec, int &yPrec,
                        int &x, int &y,
                        float valeurNull);
    static bool next(std::vector<std::vector<float> > *matrice, 
                                    float &x, float &y,
                                    int direction,
                                    float valeurNull);
    static int findType(std::vector<std::vector<float> > *matrice, 
                        float x, float y,
                        float valeurNull);
    static int findType(std::vector<std::vector<float> > *matrice, 
                        float x, float y, int direction,
                        float valeurNull);
       /// shows the number of direction  
    static int numberOf(std::vector<std::vector<float> > *matrice, 
                                int x, int y,
                                float valeurNull);

    static int findAndType(std::vector<std::vector<float> > *matrice, 
                                int &x, int &y,
                                float valeurNull);
    static int findNextAndType(std::vector<std::vector<float> > *matrice, 
                                int &xPrec, int &yPrec,
                                int &x, int &y,
                                float valeurNull);  
    static int findNextAndType(std::vector<std::vector<float> > *matrice, 
                            float &x, float &y, int direction,
                            float valeurNull);  
};





#endif