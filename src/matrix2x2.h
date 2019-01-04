#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include "vector2.h"

class Matrix2x2{
	public:
		Matrix2x2(double a, double b, double c, double d);
		Vector2 operator*(const Vector2& point) const;
		static Vector2 rotate(const Vector2& point, float theta);
		static Vector2 scale(const Vector2& point, float xScale, float yScale);
	private:
		double _array[2][2];
};

#endif
