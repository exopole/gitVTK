#include "DataPachymetry.h"



/***
*\fn DataPachymetry::DataPachymetry(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior, 
								Point center, float valeurNull, int use)
*\brief constructeur de l'objet DataPachymetry
*\param anterior : vector 2D de float représentant la face antérieur
*\param posterior : vecteur 2D de float représentant la face postérieur
*\param center : Point => coordonée du centre de la BFS
*\param valeurNull : float => remplace Null dans les données
*\param use : renseigne sur quel méthode de construction est utilsé
*/
DataPachymetry::DataPachymetry(std::vector<std::vector<float> > *anterior, std::vector<std::vector<float> > *posterior,  std::vector<float> *coordXY,
								Point* center, float valeurNull, int use)
{
	this->center = center;
	center->print();
	nombreIntersect = 0;
	this->coordXY = coordXY;
	UtilsVector::initVector(coordIntersect, 101);
	UtilsVector::initVector(this->anterior, valeurNull, 101);
	std::cout << "fin des initialisation" << std::endl;
	if (use == 1){
		DataPachymetry::constructCoord(anterior, posterior, valeurNull);
	}
	else {
		
		DataPachymetry::constructCoordV2(anterior, posterior, valeurNull);
	}
}

/***
*\fn DataPachymetry::DataPachymetry(ParserTopos &dataTopos, float valeurNull, int use)
*\brief constructeur de l'objet DataPachymetry
*\param toposParsert 
*\param valeurNull : float => remplace Null dans les données
*\param use : renseigne sur quel méthode de construction est utilsé
*/
DataPachymetry::DataPachymetry(ParserTopos *dataTopos, float valeurNull, int use){
	center = dataTopos->getCoordBFSAnterior();
	nombreIntersect =0;
	UtilsVector::initVector(coordIntersect, 101);
	UtilsVector::initVector(this->anterior, valeurNull, 101);
	std::cout << "fin des initialisation" << std::endl;
	DataPachymetry::constructCoordV3(dataTopos->getAnteriorData(), dataTopos->getPosteriorData(), valeurNull);

}



/***
*\fn void DataPachymetry::constructCoordV(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior,
									float valeurNull)
*\brief construit le vecteur de Point qui représentera la pachymetry
*\param anterior : vector 2D de float représentant la face antérieur
*\param posterior : vecteur 2D de float représentant la face postérieur
*\param valeurNull : float => remplace Null dans les données
*/
void DataPachymetry::constructCoord(std::vector<std::vector<float> > *anterior, std::vector<std::vector<float> > *posterior,
									float valeurNull)
{	
	int  xP(0), yP(0);
	float u(0), v(0), t(0);
	int x(0);
	bool intersectTrouver = false;
	int triangleTrouver = 0;
	Point pointIntersect;
	Triangle newTriangle;
	Point *V0;
	std::string name = "triangle trouver";
	//Utils::showProgress(xP, coordIntersect.size(),100,  name);
	for (xP; xP < posterior->size(); xP++)
	{
		for (yP=0; yP < posterior->at(xP).size(); yP++)
		{
			
			if (posterior->at(xP)[yP] != valeurNull)
			{
				V0->setCoordonne(xP, yP, posterior->at(xP)[yP]);

				for (int i = 1; i <= 2; i++)
					if ( newTriangle.findTriangleFromMatriceAndV0(V0, posterior, valeurNull, i)){
						newTriangle.setAllX(coordXY);
						newTriangle.setAllY(coordXY);
						DataPachymetry::findPointIntersect(&newTriangle, valeurNull, anterior);
					}

			}
			//Utils::showProgress(xP, nombreIntersect, posterior.size()-1 ,  name);

		}
	}

	std::cout << "\nnombre de triangle : " << nombreIntersect  << std::endl;
	//UtilsVector::printVector(anterior);
}


/***
*\fn void DataPachymetry::constructCoordV2(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior,
									float valeurNull)
*\brief construit le vecteur de Point qui représentera la pachymetry
*\param anterior : vector 2D de float représentant la face antérieur
*\param posterior : vecteur 2D de float représentant la face postérieur
*\param valeurNull : float => remplace Null dans les données
*/
void DataPachymetry::constructCoordV2(std::vector<std::vector<float> >* anterior, std::vector<std::vector<float> > *posterior,
									float valeurNull)
{	
	int  xP(0), yP(0);
	float u(0), v(0), t(0);
	int x(0);
	bool intersectTrouver = false;
	int triangleTrouver = 0;
	Point pointIntersect;
	Triangle newTriangle;
	Point* V0;
	std::string name = "triangle trouver";
	//Utils::showProgress(xP, coordIntersect.size(),100,  name);
	for (xP; xP < posterior->size(); xP++)
	{
		for (yP=0; yP < posterior->at(xP).size(); yP++)
		{
			
			if (posterior->at(xP)[yP] != valeurNull)
			{
				V0->setCoordonne(xP, yP, posterior->at(xP)[yP]);

				for (int i = 1; i <= 2; i++)
					if ( newTriangle.findTriangleFromMatriceAndV0(V0, posterior, valeurNull, i)){
						newTriangle.setAllX(0.1, 2);
						newTriangle.setAllX(-5, 1);
						newTriangle.setAllY(0.1, 2);
						newTriangle.setAllY(-5, 1);
						DataPachymetry::findPointIntersectV2(&newTriangle, valeurNull, anterior);
					}

			}
			//Utils::showProgress(xP, nombreIntersect, posterior.size()-1 ,  name);

		}
	}

	std::cout << "\nnombre de triangle : " << nombreIntersect  << std::endl;
	//UtilsVector::printVector(anterior);
}

/***
*\fn void DataPachymetry::constructCoordV2(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior,
									float valeurNull)
*\brief construit le vecteur de Point qui représentera la pachymetry
*\param anterior : vector 2D de float représentant la face antérieur
*\param posterior : vecteur 2D de float représentant la face postérieur
*\param valeurNull : float => remplace Null dans les données
*/
void DataPachymetry::constructCoordV3(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior,
									float valeurNull)
{	
	int  xP(0), yP(0);
	float u(0), v(0), t(0);
	int x(0);
	bool intersectTrouver = false;
	int triangleTrouver = 0;
	Point pointIntersect;
	Triangle newTriangle;
	Point *V0;
	std::string name = "triangle trouver";
	//Utils::showProgress(xP, coordIntersect.size(),100,  name);
	for (xP; xP < posterior.size(); xP++)
	{
		for (yP=0; yP < posterior[xP].size(); yP++)
		{
			
			if (anterior[xP][yP] != valeurNull)
			{
				V0->setCoordonne(xP, yP, posterior[xP][yP]);

				for (int i = 1; i <= 2; i++)
					if ( newTriangle.findTriangleFromMatriceAndV0(V0, &posterior, valeurNull, i)){
						newTriangle.setAllX(0.1, 2);
						newTriangle.setAllX(-5, 1);
						newTriangle.setAllY(0.1, 2);
						newTriangle.setAllY(-5, 1);
						DataPachymetry::findPointIntersectV2(&newTriangle, valeurNull, &anterior);
					}

			}
			//Utils::showProgress(xP, nombreIntersect, posterior.size()-1 ,  name);

		}
	}

	std::cout << "\nnombre de triangle : " << nombreIntersect  << std::endl;
	//UtilsVector::printVector(anterior);
}


/***
*\fn void DataPachymetry::findPointIntersect(Triangle triangle, 
										float valeurNull,
										std::vector<std::vector<float> >  matrice)
*\brief cherche les points d'intersection entre les rayons partant de la face antérieur et allant au centre de la BFS avec un triangle
*\param matrice : vector 2D de float => face antérieur
*\param triangle : Triangle => utiliser pour trouver les point d'intersection
*\param valeurNull : float => remplace Null dans les données
*/
void DataPachymetry::findPointIntersect(Triangle* triangle, 
										float valeurNull,
										std::vector<std::vector<float> >*  matrice){

	bool intersectTrouver = false;
	std::vector<Point>  tmp;
	int x(0), y(0);
	int fin(0);
	float t, u, v;
	//std::cout << "size : " << anterior.size() << std::endl;

	while ( x < matrice->size()){
		while (y < matrice->at(x).size()){
				//std::cout << "Problem" << std::endl;

			if (matrice->at(x)[y] != valeurNull && anterior->at(x)[y] == valeurNull ){
				Vec3f orig(-5 + x * 0.1, -5 + y * 0.1, matrice->at(x)[y]);
				Vec3f dir(-5 + x * 0.1 - center->getX(), -5 + y * 0.1 - center->getY(), matrice->at(x)[y] - center->getZ());
				dir.normalize();

				if (UtilsGeometry::rayTriangleIntersect(orig, dir, 
														triangle->V0Vec3f(), triangle->V1Vec3f(), triangle->V2Vec3f(), 
														t, u , v))
				{
					coordIntersect->at(x)[y].setCoordonne(t, u, v);
					anterior->at(x)[y] = matrice->at(x)[y];
					nombreIntersect ++;

				}
			}
			y++;
		}
		x++;
		y = 0;
	}
}

/***
*\fn void DataPachymetry::findPointIntersect(Triangle triangle, 
										float valeurNull,
										std::vector<std::vector<float> >  matrice)
*\brief cherche les points d'intersection entre les rayons partant de la face antérieur et allant au centre de la BFS avec un triangle
*\param matrice : vector 2D de float => face antérieur
*\param triangle : Triangle => utiliser pour trouver les point d'intersection
*\param valeurNull : float => remplace Null dans les données
*/
void DataPachymetry::findPointIntersectV2(Triangle* triangle, 
										float valeurNull,
										std::vector<std::vector<float> >*  matrice){

	bool intersectTrouver = false;
	std::vector<Point>  tmp;
	int x(0), y(0);
	int fin(0);
	Point I;
	//std::cout << "size : " << anterior.size() << std::endl;

	while ( x < matrice->size()){
		while (y < matrice->at(x).size()){
				//std::cout << "Problem" << std::endl;

			if (matrice->at(x)[y] != valeurNull && anterior->at(x)[y] == valeurNull ){
				Point orig(-5 + x * 0.1, -5 + y * 0.1, matrice->at(x)[y]);
				Ray R(orig, *center);

				if (UtilsGeometry::intersect3D_RayTriangle( R, *triangle, &I ) == 1)
				{
					coordIntersect->at(x)[y].copy(I);
					nombreIntersect++;
				}
					  
			}
			y++;
		}
		x++;
		y = 0;
	}
}

/***
*\fn std::vector<std::vector<float> > DataPachymetry::getAnterior()
*\brief Permet d'avoir les coordonnées d'élévation de la face antérieur
*\param void
*\return vecteur 2D de float
*/
std::vector<std::vector<float> >* DataPachymetry::getAnterior(){
	return anterior;
}


/***
*\fn std::vector<std::vector<float> > DataPachymetry::getCoord()
*\brief Permet d'avoir les coordonnées d'intersection
*\param void
*\return vecteur 2D de point
*/
std::vector<std::vector<Point> >* DataPachymetry::getCoord(){
	return coordIntersect;
}

DataPachymetry::~DataPachymetry()
{

}

