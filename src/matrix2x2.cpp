#include "matrix2x2.h"
#include <math.h>


Matrix2x2::Matrix2x2(double a, double b, double c, double d){
	_array[0][0] = a;
	_array[0][1] = b;
	_array[1][0] = c;
	_array[1][1] = d;
}


Vector2 Matrix2x2::operator*(const Vector2& point) const{
	return Vector2(_array[0][0] * point.x() + _array[0][1] * point.y(), _array[1][0] * point.x() + _array[1][1] * point.y());
}

Vector2 Matrix2x2::rotate(const Vector2& point, float theta){
	Matrix2x2 rotationMatrix = Matrix2x2(cos(theta), -sin(theta), sin(theta), cos(theta));
	return rotationMatrix * point;
}

Vector2 Matrix2x2::scale(const Vector2& point, float xScale, float yScale){
	Matrix2x2 scaleMatrix = Matrix2x2(xScale, 0, 0, yScale);
	return scaleMatrix * point;
}
