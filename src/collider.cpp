#include"collider.h"
#include"engine.h"

Collider::Collider(const Transform& transform, const std::string& name, bool solid/*=false*/, bool fixed/*=false*/)
	: Drawable(transform, name)
	, _solid(solid)
	, _fixed(fixed){}


void Collider::registerWithEngine(Engine* engine){
	engine->register_collider(this);
}

void Collider::setDraw(bool draw){
	_draw = draw;
}

bool Collider::draw() const{
	return _draw;
}

bool Collider::solid() const{
	return _solid;
}

bool Collider::fixed() const{
	return _fixed;
}

void Collider::onCollision(Collider* other){
	// To be overridden
}

