#ifndef UTILS_H
#define UTILS_H

#include "iostream"
#include "string"

class Utils
{
public:
	static void showProgress(float progress1, int progress2, float objectif, std::string name);
	static void simplificationFraction(int &numerateur , int &denominateur);
	/// find the greatest common divisor (PGCD)
	static int PGCD(int numerateur , int denominateur);

};

#endif