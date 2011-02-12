
#include "Vector.h"


Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


//	vector operations

Vector Vector::operator*(double scalar)
{
	double new_x = scalar * this->x;
	double new_y = scalar * this->y;
	double new_z = scalar * this->z;
	
	return Vector(new_x, new_y, new_z);
}

double Vector::operator*(const Vector &other)	//	dot product
{
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

Vector Vector::operator+(const Vector &other)
{
	double new_x = this->x + other.x;
	double new_y = this->y + other.y;
	double new_z = this->z + other.z;
	
	return Vector(new_x, new_y, new_z);
}

Vector Vector::operator-(const Vector &other)
{
	double new_x = this->x - other.x;
	double new_y = this->y - other.y;
	double new_z = this->z - other.z;
	
	return Vector(new_x, new_y, new_z);
}





double Vector::angle()
{
	double angle = atan(y / x);
	
	if ( x == 0 )
		angle = PI / 2;
	else if ( x < 0 )
		angle += PI;
	
	return angle;
}

double Vector::magnitude()
{
	return sqrt( pow(x, 2) + pow(y, 2) + pow(z, 2) );
}




