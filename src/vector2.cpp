#include "vector2.h"
#include "geometry.h"
#include<math.h>
#include<string>

Vector2::Vector2()
	: _x(0)
	, _y(0){}

Vector2::Vector2(double x, double y)
	: _x(x)
	, _y(y){}

// Cast to string operator
Vector2::operator std::string() const{
	std::string s("(");
	s.append(std::to_string(_x));
	s.append(", ");
	s.append(std::to_string(_y));
	s.append(")");
	return s;
}

void Vector2::operator=(const Vector2 & other){
	_x = other.x();
	_y = other.y();
}

bool Vector2::operator==(const Vector2& other) const{
	return (_x == other.x() && _y == other.y());
}

Vector2 Vector2::operator-(const Vector2 & other) const{
	return Vector2(_x - other.x(), _y - other.y());
}

Vector2 Vector2::operator+(const Vector2 & other) const{
	return Vector2(_x + other.x(), _y + other.y());
}

Vector2 Vector2::operator*(const double & scalar) const{
	return Vector2(_x * scalar, _y * scalar);
}

// Global function for commutivity
Vector2 operator*(const double& lhs, const Vector2& rhs){
	return rhs * lhs;
}

const double Vector2::dot(const Vector2& other) const{
	return _x * other.x() + _y * other.y();
}

const Vector2 Vector2::projectOnto(const Vector2& other) const{
	double dotProd = dot(other);
	return (dotProd / pow(other.magnitude(),2)) * other;
}

const double Vector2::x() const{
	return _x;
}

const double Vector2::y() const{
	return _y;
}

double Vector2::magnitude() const{
	return sqrt(pow(_x, 2) + pow(_y, 2));
}

Vector2 Vector2::normalized() const{
	double mag = magnitude();
	return Vector2(_x / mag, _y / mag);
}

void Vector2::normalize(){
	double mag = magnitude();
	_x = _x / mag;
	_y = _y / mag;
}
