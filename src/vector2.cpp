#include "vector2.h"
#include "geometry.h"
#include<math.h>

Vector2::Vector2(double x, double y)
	: _x(x)
	, _y(y){}

void Vector2::operator=(const Vector2 & other){
	_x = other.x();
	_y = other.y();
}

Vector2 Vector2::operator-(const Vector2 & other){
	return Vector2(_x - other.x(), _y - other.y());
}

Vector2 Vector2::operator+(const Vector2 & other){
	return Vector2(_x + other.x(), _y + other.y());
}

Vector2 Vector2::operator*(const double & scalar) const{
	return Vector2(_x * scalar, _y * scalar);
}

// Global function for commutivity
Vector2 operator*(const double& lhs, const Vector2& rhs){
	return rhs * lhs;
}

const double Vector2::dot(Vector2 other) const{
	return _x * other.x() + _y * other.y();
}

const Vector2 Vector2::projectOnto(Vector2 other) const{
	double dotProd = dot(other);
	return (dotProd / pow(length(Vector2(0,0),other),2)) * other;
}

const double Vector2::x() const{
	return _x;
}

const double Vector2::y() const{
	return _y;
}
