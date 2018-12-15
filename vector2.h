#ifndef VECTOR_H
#define VECTOR_H

class Vector2{
	public:
		Vector2(int x, int y);
		void operator=(const Vector2& other);
		Vector2 operator-(const Vector2& other);
		Vector2 operator+(const Vector2& other);
		const int x() const;
		const int y() const;
		
	private:
		int _x, _y;

};



#endif
