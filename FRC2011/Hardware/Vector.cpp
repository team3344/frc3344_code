
#include "wpilib.h"


Vector::Vector(double x, double y, double z = 0)
{
	this.x = x;
	this.y = y;
	this.z = z;
}

Vector::Vector(double magnitude, double angle)
{
	this.x = magnitude * cos(angle);
	this.y = magnitude * sin(angle);
}


//	vector operations

Vector Vector::operator*(double scalar)
{
	double new_x = scalar * this.x;
	double new_y = scalar * this.y;
	double new_z = scalar * this.z;
	
	return Vector(new_x, new_y, new_z);
}

double Vector::operator*(const Vector &other)	//	dot product
{
	return (this.x * other.x) + (this.y * other.y) + (this.z * other.z);
}

Vector Vector::operator+(const Vector &other)
{
	double new_x = this.x + other.x;
	double new_y = this.y + other.y;
	double new_z = this.z + other.z;
	
	return Vector(new_x, new_y, new_z);
}

Vector Vector::operator-(const Vector &other)
{
	double new_x = this.x - other.x;
	double new_y = this.y - other.y;
	double new_z = this.z - other.z;
	
	return Vector(new_x, new_y, new_z);
}

