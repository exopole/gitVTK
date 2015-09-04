#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>

template <typename T>
class Vecteur3D
{
public:

	/**
	* \fn Vecteur3D()
	* \brief constructor of a null vector
	* x = 0, y = 0, z = 0
	*/
	Vecteur3D(): x(T(0)), y(T(0)), z(T(0)) {} 

	/**
	* \fn Vecteur3D(T xx)
	* \brief constructor of a vector
	* x = xx, y = xx, z = xx
	*/
	Vecteur3D(T xx) : x(xx), y(xx), z(xx) {}

	/**
	* \fn Vecteur3D(T xx, T yy, T zz)
	* \brief constructor of a vector
	* x = xx, y = yy, z = zz
	*/
	Vecteur3D(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
	
	/**
	* \fn Vecteur3D operator + (const Vecteur3D &v) const 
	* \brief operator + 
	* x + v.x, y + v.y, z + v.z
	*/
	Vecteur3D operator + (const Vecteur3D &v) const { 
		return Vecteur3D(x + v.x, y + v.y, z + v.z); 
	}

	/**
	* \fn Vecteur3D operator - (const Vecteur3D &v) const 
	* \brief operator - 
	* x - v.x, y - v.y, z - v.z
	*/
	Vecteur3D operator - (const Vecteur3D &v) const {
		return Vecteur3D(x - v.x, y - v.y, z - v.z); 
	}

	/**
	* \fn Vecteur3D operator - () const 
	* \brief operator - 
	* -x, -y, -z
	*/
	Vecteur3D operator - () const {
	 	return Vecteur3D(-x, -y, -z); 
	}

	/**
	* \fn Vecteur3D operator * (const T &r) const 
	* \brief operator * 
	* x * r, y * r, z * r
	*/
	Vecteur3D operator * (const T &r) const {
	 	return Vecteur3D(x * r, y * r, z * r); 
	}

	/**
	* \fn Vecteur3D operator * (const Vecteur3D &v) const 
	* \brief operator * 
	* x * r, y * r, z * r
	*/
	Vecteur3D operator * (const Vecteur3D &v) const {
	 	return Vecteur3D(x * v.x, y * v.y, z * v.z); 
	}

	/**
	* \fn Vecteur3D operator /= (const T &r)
	* \brief operator /= 
	* x /= r, y /= r, z /= r
	*/
	Vecteur3D operator /= (const T &r){
		x /= r;
		y /= r;
		z /= r;
		return *this;
	}

	/**
	* \fn Vecteur3D operator *= (const T &r)
	* \brief operator *= 
	* x *= r, y *= r, z *= r
	*/
	Vecteur3D operator *= (const T &r){
		x *= r;
		y *= r;
		z *= r;
		return *this;
	}

	/**
	* \fn crossProduct(const Vecteur3D<T> &v) const
	* \brief cross product  
	* y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x
	*/
	Vecteur3D crossProduct(const Vecteur3D<T> &v) const{
	return Vecteur3D<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	/**
	* \fn dotProduct(const Vecteur3D<T> &v) const
	* \brief dot product  
	* x * v.x + y * v.y + z * v.z
	*/
	T dotProduct(const Vecteur3D<T> &v) const{
		return x * v.x + y * v.y + z * v.z;
	}

	/**
	* \fn dotProduct(const Vecteur3D<T> &v) const
	* \brief normalisation 
	* x * x + y * y + z * z
	*/
	T norm() const{
		return x * x + y * y + z * z;
	}

	/**
	* \fn T length() const
	* \brief the length of the vector 
	*/
	T length() const{
		return sqrt(norm());
	}

	/**
	* \fn const T& operator [] (int i)
	* \brief 
	*/
	const T& operator [] (int i) { 
		return (&x)[i]; 
	}

	/**
	*\fn T& normalize()
	* 
	*/
	T& normalize(){
		T n = norm();
		if (n > 0) {
			T factor = 1 / sqrt(n);
			x *= factor, y *= factor, z *= factor;
		}

		return *this;
	}
		
	// point of the vector coordonate 
	T x, y, z;
		
};

template <class F>
Vecteur3D<F> operator * (const F &r, const Vecteur3D<F> &v){ 
	return Vecteur3D<F>(v.x * r, v.y * r, v.z * r); 
}

template <class F>
Vecteur3D<F> operator / (const F &r, const Vecteur3D<F> &v){ 
	return Vecteur3D<F>(r / v.x, r / v.y, r / v.z); 
}
template <class F>
std::ostream& operator << (std::ostream &s, const Vecteur3D<F> &v){
    return s << '[' << v.x << ' ' << v.y << ' ' << v.z << ']';
}

typedef Vecteur3D<float> Vec3f;
typedef Vecteur3D<int> Vec3i;

#endif