

#ifndef VECTOR_H_
#define VECTOR_H_



class Vector {

	Vector(double x, double y, double z = 0);
	Vector(double magnitude, double angle);

	
	Vector operator*(double scalar);	//	scalar multiplication
	double operator*(const Vector &other);	//	dot product
	
	Vector operator+(const Vector &other);	//	vector addition & subtraction
	Vector operator-(const Vector &other);	//
	
	
	//	components
	double x, y, z;
};


#endif /* VECTOR_H_ */
