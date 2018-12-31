#ifndef TRANSFORM_H
#define TRNASFORM_H

#include "vector2.h"

class Transform {
	public:
		Transform(const Vector2& position);
		Transform(const Vector2& position, double rotation, const Vector2& scale);
		
		void setPosition(const Vector2& position);
		void setRotation(double rotation);
		void setScale(const Vector2& scale);

		Vector2 position() const;
		double rotation() const;
		Vector2 scale() const;

	protected:
		Vector2 _position;
		double _rotation;
		Vector2 _scale;


};


#endif
