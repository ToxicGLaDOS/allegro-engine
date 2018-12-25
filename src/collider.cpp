#include"collider.h"

Collider::Collider(const Vector2& pos, const std::string& name)
	: Drawable(pos,name){}



void Collider::setDraw(bool draw){
	_draw = draw;
}

bool Collider::draw() const{
	return _draw;
}

void Collider::onCollision(Collider* other){
	// To be overridden
}

