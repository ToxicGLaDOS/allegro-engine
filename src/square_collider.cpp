#include "square_collider.h"
#include <allegro5/allegro_primitives.h>


SquareCollider::SquareCollider()
	: Object(Vector2(0,0), "NULL")
	,_size(Vector2(0,0)){}

SquareCollider::SquareCollider(Vector2 position, Vector2 size, std::string name)
	: Object(position, name)
	, _size(size){}

bool SquareCollider::collides(SquareCollider other){
	SquareCollider left, right, top, bottom;
	if(_position.x() < other._position.x()){
		left = *this;
		right = other;
	}
	else{
		left = other;
		right = *this;
	}
	if(_position.y() < other._position.y()){
		top = *this;
		bottom = other;
	}
	else{
		top = other;
		bottom = *this;
	}

	if(left._position.x() + left._size.x() > right._position.x() && top._position.y() + top._size.y() > bottom._position.y()){
		return true;
	}
	else{
		return false;
	}

}

void SquareCollider::draw(){
	al_draw_line(_position.x(),           _position.y(),           _position.x()+_size.x(), _position.y(),           draw_color, 1);
	al_draw_line(_position.x(),           _position.y(),           _position.x(),           _position.y()+_size.y(), draw_color, 1);
	al_draw_line(_position.x()+_size.x(), _position.y(),           _position.x()+_size.x(), _position.y()+_size.y(), draw_color, 1);
	al_draw_line(_position.x(),           _position.y()+_size.y(), _position.x()+_size.x(), _position.y()+_size.y(), draw_color, 1);
}
