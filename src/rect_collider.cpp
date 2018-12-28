#include "rect_collider.h"
#include "circle_collider.h"
#include "geometry.h"
#include <allegro5/allegro_primitives.h>


RectCollider::RectCollider()
	: Collider(Vector2(0,0), "")
	,_size(Vector2(0,0)){
	
	initBitmap();
}

RectCollider::RectCollider(const Vector2& position, const Vector2& size, const std::string& name)
	: Collider(position, name)
	, _size(size){
	
	initBitmap();	
}

RectCollider::RectCollider(const RectCollider& other)
	: Collider(other._position, other._name)
	, _bitmap(al_clone_bitmap(other._bitmap))
	, _size(other._size){}

RectCollider::~RectCollider(){
	al_destroy_bitmap(_bitmap);
}

void RectCollider::initBitmap(){
	_bitmap = al_create_bitmap(_size.x(),_size.y());
	al_set_target_bitmap(_bitmap);
	al_clear_to_color(al_map_rgba(0,0,0,0));

	// Magic number 1's are so that it fits in the bitmap
	// 0 is outside the bitmap for some reason on the left and 
	// the size of the bitmap is outside on thebottom
	al_draw_line(0,         0,           _size.x(),     0,           al_map_rgb(0, 200, 0), 1);
	al_draw_line(1,         0,           1,             _size.y(),   al_map_rgb(0, 200, 0), 1);
	al_draw_line(_size.x(), 0,           _size.x(),     _size.y(),   al_map_rgb(0, 200, 0), 1);
	al_draw_line(0,         _size.y()-1, _size.x(),     _size.y()-1, al_map_rgb(0, 200, 0), 1);

}


bool RectCollider::collides(Collider * other) const{	
	RectCollider* square_ptr = dynamic_cast<RectCollider*>(other);
	CircleCollider* circle_ptr = dynamic_cast<CircleCollider*>(other);	
	if(square_ptr != NULL){
		RectCollider square = *square_ptr;
		return rectRectIntersection(_position, _size, square.position(), square.size());
	}
	if(circle_ptr != NULL){
		CircleCollider circle = *circle_ptr;
		return rectCircleIntersection(_position, _size, circle.position(), circle.radius());
	}
}

Vector2 RectCollider::topLeft() const{
	return _position;
}

ALLEGRO_BITMAP * RectCollider::getBitmap() const{
	return _bitmap;
}

Vector2 RectCollider::size() const{
	return _size;
}


