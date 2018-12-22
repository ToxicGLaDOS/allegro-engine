#include"collider.h"

Collider::Collider(Vector2 pos, std::string name)
	: Drawable(pos,name){}



void Collider::setDraw(bool draw){
	_draw = draw;
}

bool Collider::draw(){
	return _draw;
}

