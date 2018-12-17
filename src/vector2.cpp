#include "vector2.h"


Vector2::Vector2(int x, int y)
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

const int Vector2::x() const{
	return _x;
}

const int Vector2::y() const{
	return _y;
}
