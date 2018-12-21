#include "square_collider.h"
#include "circle_collider.h"
#include "geometry.h"
#include <allegro5/allegro_primitives.h>


SquareCollider::SquareCollider()
	: Collider(Vector2(0,0), "NULL")
	,_size(Vector2(0,0)){}

SquareCollider::SquareCollider(Vector2 position, Vector2 size, std::string name)
	: Collider(position, name)
	, _size(size){}

bool SquareCollider::collides(Collider * other){	
	SquareCollider* square_ptr = dynamic_cast<SquareCollider*>(other);
	CircleCollider* circle_ptr = dynamic_cast<CircleCollider*>(other);	
	if(square_ptr != NULL){
		SquareCollider square = *square_ptr;
		return rectRectIntersection(_position, _size, square.position(), square.size());
	}
	if(circle_ptr != NULL){
		CircleCollider circle = *circle_ptr;
		return rectCircleIntersection(_position, _size, circle.position(), circle.radius());
	}

}

void SquareCollider::draw(ALLEGRO_COLOR draw_color, int width){
	al_draw_line(_position.x(),           _position.y(),           _position.x()+_size.x(), _position.y(),           draw_color, width);
	al_draw_line(_position.x(),           _position.y(),           _position.x(),           _position.y()+_size.y(), draw_color, width);
	al_draw_line(_position.x()+_size.x(), _position.y(),           _position.x()+_size.x(), _position.y()+_size.y(), draw_color, width);
	al_draw_line(_position.x(),           _position.y()+_size.y(), _position.x()+_size.x(), _position.y()+_size.y(), draw_color, width);
}

Vector2 SquareCollider::size(){
	return _size;
}


