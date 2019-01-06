#include"collider.h"

Collider::Collider(const Transform& transform, const std::string& name, bool solid/*=false*/, bool fixed/*=false*/)
	: Drawable(transform, name)
	, _solid(solid)
	, _fixed(fixed){}



void Collider::setDraw(bool draw){
	_draw = draw;
}

bool Collider::draw() const{
	return _draw;
}

void Collider::onCollision(Collider* other){
	// To be overridden
}

