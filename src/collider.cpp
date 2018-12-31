#include"collider.h"

Collider::Collider(const Transform& transform, const std::string& name)
	: Drawable(transform, name){}



void Collider::setDraw(bool draw){
	_draw = draw;
}

bool Collider::draw() const{
	return _draw;
}

void Collider::onCollision(Collider* other){
	// To be overridden
}

