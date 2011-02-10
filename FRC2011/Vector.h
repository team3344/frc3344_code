

#ifndef VECTOR_H_
#define VECTOR_H_

#include "Defines.h"



class Vector {

	Vector(double x, double y, double z);
	
	Vector operator*(double scalar);	//	scalar multiplication
	double operator*(const Vector &other);	//	dot product
	
	Vector operator+(const Vector &other);	//	vector addition & subtraction
	Vector operator-(const Vector &other);	//
	
	
	double angle();
	double magnitude();
	
	
	//	components
	double x, y, z;
};


#endif /* VECTOR_H_ */
