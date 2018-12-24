#ifndef VECTOR_H
#define VECTOR_H

class Vector2{
	public:
		Vector2();
		Vector2(double x, double y);
		void operator=(const Vector2& other);
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator*(const double & scalar) const;
		const double dot(const Vector2& other) const;
		const Vector2 projectOnto(const Vector2& other) const;
		const double x() const;
		const double y() const;
		
	private:
		double _x, _y;

};



#endif
