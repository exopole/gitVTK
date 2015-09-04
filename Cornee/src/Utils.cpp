#include "Utils.h"


void Utils::showProgress(float progress1, int progress2, float objectif1, std::string name){
	float count1 = (progress1/objectif1)*100;
	int count2 = progress2;
	std::cout << "\r" << "Progression : " << count1 << " % " << count2 << " " << name  ;
}


void Utils::simplificationFraction(int &numerateur , int &denominateur){
	int diviseur = Utils::PGCD(numerateur , denominateur);
	numerateur /= diviseur;
	denominateur /= diviseur;

}

int Utils::PGCD(int numerateur , int denominateur){
	int diviseur;
	while (denominateur!=0){
		diviseur = numerateur % denominateur;
		numerateur = denominateur;
		denominateur = diviseur;
	}
	return numerateur;
}