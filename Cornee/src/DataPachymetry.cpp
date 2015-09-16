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
								Point* center, float valeurNull)
{
	this->center = center;
	center->print();
	nombreIntersect = 0;
	//this->coordXY = *(coordXY);
	UtilsVector::initVector(&coordIntersect, 101);
	UtilsVector::initVector(&(this->anterior), valeurNull, 101);
	std::cout << "fin des initialisation" << std::endl;
	DataPachymetry::constructCoord(anterior, posterior, valeurNull);

}

/***
*\fn DataPachymetry::DataPachymetry(ParserTopos &dataTopos, float valeurNull, int use)
*\brief constructeur de l'objet DataPachymetry
*\param toposParsert 
*\param valeurNull : float => remplace Null dans les données
*\param use : renseigne sur quel méthode de construction est utilsé
*/
DataPachymetry::DataPachymetry(ParserTopos *dataTopos, float valeurNull){
	center = dataTopos->getCoordBFSAnterior();
	center.print();
	coordXY = dataTopos->getCoordXY();
	nombreIntersect =0;
	UtilsVector::initVector(&coordIntersect, 101);
	anterior = UtilsVector::initVector(valeurNull, 101);
	pachymetry = UtilsVector::initVector(valeurNull, 101);
	DataPachymetry::constructCoord(dataTopos->getAnteriorData(), dataTopos->getPosteriorData(), valeurNull);

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
						DataPachymetry::findPointIntersectV3(&newTriangle, valeurNull, anterior);
					}

			}
			//Utils::showProgress(xP, nombreIntersect, posterior.size()-1 ,  name);

		}
	}

	std::cout << "\nnombre de triangle : " << nombreIntersect  << std::endl;
	//UtilsVector::printVector(anterior);
}

/***
*\fn void DataPachymetry::constructCoordV(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior,
									float valeurNull)
*\brief construit le vecteur de Point qui représentera la pachymetry
*\param anterior : vector 2D de float représentant la face antérieur
*\param posterior : vecteur 2D de float représentant la face postérieur
*\param valeurNull : float => remplace Null dans les données
*/
void DataPachymetry::constructCoord(std::vector<std::vector<float> > anterior, std::vector<std::vector<float> > posterior,
									float valeurNull)
{	
	int  xP(0), yP(0);
	float u(0), v(0), t(0);
	int x(0);
	bool intersectTrouver = false;
	int triangleTrouver = 0;
	Point pointIntersect;
	Triangle newTriangle1, newTriangle2;
	Point V0, V1, V2, V3;
	std::string name = "triangle trouver";
	//Utils::showProgress(xP, coordIntersect.size(),100,  name);
	for (xP; xP < posterior.size()-1; xP++)
	{
		for (yP=0; yP < posterior[xP].size()-1; yP++)
		{
			if (posterior[xP][yP] != valeurNull)
			{
				V0.setCoordonne(xP, yP, posterior[xP][yP]);
				V1.setCoordonne(xP+1, yP, posterior[xP+1][yP]);
				V2.setCoordonne(xP+1, yP+1, posterior[xP+1][yP+1]);
				V3.setCoordonne(xP, yP+1, posterior[xP][yP+1]);
				newTriangle1.setCoordonne(&V0, &V1, &V2);
				newTriangle2.setCoordonne(&V0, &V3, &V2);
				
				if (! newTriangle1.containZValue(valeurNull))
				{

					//std::cout << "newTriangle1 !!!!!!!!!!!!!!!!!!!!!!! " << std::endl;
					//newTriangle1.print();
					newTriangle1.setAllX(coordXY);
					newTriangle1.setAllY(coordXY);
					//UtilsVector::printVector(coordXY);
					//std::cout << "newTriangle1 V2222222222 !!!!!!!!!!!!!!!!!!!!!!! " << std::endl;
					//newTriangle1.print();
					DataPachymetry::findPointIntersect(&newTriangle1, valeurNull, &anterior);
				}

				if (! newTriangle2.containZValue(valeurNull))
				{

					//std::cout << "newTriangle1 !!!!!!!!!!!!!!!!!!!!!!! " << std::endl;
					//newTriangle1.print();
					newTriangle2.setAllX(coordXY);
					newTriangle2.setAllY(coordXY);
					//UtilsVector::printVector(coordXY);
					//std::cout << "newTriangle1 V2222222222 !!!!!!!!!!!!!!!!!!!!!!! " << std::endl;
					//newTriangle1.print();
					DataPachymetry::findPointIntersect(&newTriangle2, valeurNull, &anterior);
				}

				/**
				for (int i = 1; i <= 2; i++)
					if ( newTriangle.findTriangleFromMatriceAndV0(V0, &posterior, valeurNull, i)){
						newTriangle.setAllX(coordXY);
						newTriangle.setAllY(coordXY);
						DataPachymetry::findPointIntersect(&newTriangle, valeurNull, &anterior);
					}
					*/

			}
			//Utils::showProgress(xP, nombreIntersect, posterior.size()-1 ,  name); 

		}
	}
	std::cout << nombreIntersect << std::endl;


	UtilsVector::printVectorNonNull(coordIntersect);


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

			if (matrice->at(x)[y] != valeurNull && pachymetry[x][y] == valeurNull ){
				Vec3f orig(-5 + x * 0.1, -5 + y * 0.1, matrice->at(x)[y]);
				Vec3f dir(-5 + x * 0.1 - center.getX(), -5 + y * 0.1 - center.getY(), matrice->at(x)[y] - center.getZ());
				dir.normalize();

				if (UtilsGeometry::rayTriangleIntersect(orig, dir, 
														triangle->V0Vec3f(), triangle->V1Vec3f(), triangle->V2Vec3f(), 
														t, u , v))
				{
					coordIntersect[x][y].setCoordonne(t, u, v);
					anterior[x][y] = matrice->at(x)[y];
					pachymetry[x][y] = t*0.92;
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

			if (matrice->at(x)[y] != valeurNull && anterior[x][y] == valeurNull ){
				Point orig(-5 + x * 0.1, -5 + y * 0.1, matrice->at(x)[y]);
				Ray R( center,orig);

				if (UtilsGeometry::intersect3D_RayTriangle( R, *triangle, &I ) == 1)
				{
					coordIntersect[x][y].copy(I);
					//I.print();
					nombreIntersect++;
				}
					  
			}
			y++;
		}
		x++;
		y = 0;
	}
}




void DataPachymetry::findPointIntersectV3(Triangle* triangle, 
										float valeurNull,
										std::vector<std::vector<float> >*  matrice){

	bool intersectTrouver = false;
	std::vector<Point>  tmp;
	int x(0), y(0);
	int fin(0);
	double t, u, v;
	//std::cout << "//////////////////////////////////////////" << std::endl;
	double vert0[3] = {triangle->getV0()->getX(), triangle->getV0()->getY(), triangle->getV0()->getZ()};
	double vert1[3] = {triangle->getV1()->getX(), triangle->getV1()->getY(), triangle->getV1()->getZ()};
	double vert2[3] = {triangle->getV2()->getX(), triangle->getV2()->getY(), triangle->getV2()->getZ()};
	double dir[3] = {center.getX(), center.getY(), center.getZ()};
	/*
	std::cout << triangle->getV0()->getX() << ", " <<vert0[1] << ", " << vert0[2] << std::endl;
	std::cout << vert1[0] << ", " <<vert1[1] << ", " << vert1[2] << std::endl;
	std::cout << vert2[0] << ", " <<vert2[1] << ", " << vert2[2] << std::endl;
	std::cout << dir[0] << ", " <<dir[1] << ", " << dir[2] << std::endl;
	*/
	//std::cout << "size : " << anterior.size() << std::endl;
	//	triangle->print();
	while ( x < matrice->size()){
		while (y < matrice->at(x).size()){
				//std::cout << "Problem" << std::endl;

			if (matrice->at(x)[y] != valeurNull && anterior[x][y] == valeurNull ){
				double orig[3] = {-5 + x * 0.1, -5 + y * 0.1, matrice->at(x)[y]};
				//std::cout << orig[0] << ", " <<orig[1] << ", " << orig[2] << std::endl;

				if ( UtilsGeometry::intersect_triangle(orig, dir,vert0, vert1, vert2, &t, &u, &v)== 1)
				{
					//std::cout << "t : " << t << ", u : " << u << ", v : " << v << std::endl;
					coordIntersect[x][y].setCoordonne(t, u, v);
					pachymetry[x][y] = t*0.92;
					std::cout << t*0.92 << "; " << pachymetry[x][y] << std::endl;

					anterior[x][y] = matrice->at(x)[y];
					nombreIntersect++ ;

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
std::vector<std::vector<float> > DataPachymetry::getAnterior(){
	return anterior;
}

/***
*\fn std::vector<std::vector<float> > DataPachymetry::getAnterior()
*\brief Permet d'avoir les coordonnées d'élévation de la face antérieur
*\param void
*\return vecteur 2D de float
*/
std::vector<std::vector<float> > DataPachymetry::getPachymetry(){
	return pachymetry;
}


/***
*\fn std::vector<std::vector<float> > DataPachymetry::getCoord()
*\brief Permet d'avoir les coordonnées d'intersection
*\param void
*\return vecteur 2D de point
*/
std::vector<std::vector<Point> > DataPachymetry::getCoord(){
	return coordIntersect;
}

DataPachymetry::~DataPachymetry()
{

}

