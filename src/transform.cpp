#include "transform.h"

Transform::Transform(const Vector2& position)
	: _position(position)
	, _rotation(0)
	, _scale(Vector2(1, 1)){}

Transform::Transform(const Vector2& position, double rotation, const Vector2& scale)
	: _position(position)
	, _rotation(rotation)
	, _scale(scale){}

void Transform::setPosition(const Vector2& position){
	_position = position;
}

void Transform::setRotation(double rotation){
	_rotation = rotation;
}

void Transform::setScale(const Vector2& scale){
	_scale = scale;
}

Vector2 Transform::position() const{
	return _position;
}

double Transform::rotation() const{
	return _rotation;
}

Vector2 Transform::scale() const{
	return _scale;
}
