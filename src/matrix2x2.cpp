#include "matrix2x2.h"
#include <math.h>


Matrix2x2::Matrix2x2(double a, double b, double c, double d){
	array[0][0] = a;
	array[0][1] = b;
	array[1][0] = c;
	array[1][1] = d;
}


Vector2 Matrix2x2::operator*(const Vector2& point) const{
	return Vector2(array[0][0] * point.x() + array[0][1] * point.y(), array[1][0] * point.x() + array[1][1] * point.y());
}

Vector2 Matrix2x2::rotate(const Vector2& point, float theta){
	Matrix2x2 rotationMatrix = Matrix2x2(cos(theta), -sin(theta), sin(theta), cos(theta));
	return rotationMatrix * point;
}

Vector2 Matrix2x2::scale(const Vector2& point, float xScale, float yScale){
	Matrix2x2 scaleMatrix = Matrix2x2(xScale, 0, 0, yScale);
	return scaleMatrix * point;
}
