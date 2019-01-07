#ifndef VECTOR_H
#define VECTOR_H

#include<string>

class Vector2{
	public:
		Vector2();
		Vector2(double x, double y);
		operator std::string() const;
		void operator=(const Vector2& other);
		bool operator==(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator*(const double & scalar) const;
		const double dot(const Vector2& other) const;
		const Vector2 projectOnto(const Vector2& other) const;
		const double x() const;
		const double y() const;
		
		double magnitude() const;
		Vector2 normalized() const;
		void normalize();
		
	private:
		double _x, _y;

};



#endif
