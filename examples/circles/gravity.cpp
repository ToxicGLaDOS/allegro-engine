#include "gravity.h"

Gravity::Gravity(const Transform& trans, const std::string& name)
	: Object(trans, name){}



void Gravity::update(){
	moveBy(Vector2(0, -speed));
}
