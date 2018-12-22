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

Vector2 SquareCollider::topLeft(){
	return _position;
}

ALLEGRO_BITMAP * SquareCollider::makeBitmap(){
	ALLEGRO_BITMAP * bitmap = al_create_bitmap(_size.x(),_size.y());
	al_set_target_bitmap(bitmap);
	al_clear_to_color(al_map_rgba(0,0,0,0));

	// Magic number 1's are so that it fits in the bitmap
	// 0 is outside the bitmap for some reason on the left and 
	// the size of the bitmap is outside on thebottom
	al_draw_line(0,         0,           _size.x(),     0,           al_map_rgb(0, 200, 0), 1);
	al_draw_line(1,         0,           1,             _size.y(),   al_map_rgb(0, 200, 0), 1);
	al_draw_line(_size.x(), 0,           _size.x(),     _size.y(),   al_map_rgb(0, 200, 0), 1);
	al_draw_line(0,         _size.y()-1, _size.x(),     _size.y()-1, al_map_rgb(0, 200, 0), 1);
	return bitmap;

}

Vector2 SquareCollider::size(){
	return _size;
}


