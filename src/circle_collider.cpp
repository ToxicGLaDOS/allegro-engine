#include"circle_collider.h"
#include"rect_collider.h"
#include"geometry.h"
#include<string>
#include<allegro5/allegro_primitives.h>




CircleCollider::CircleCollider(const Vector2& pos, double radius, const std::string& name)
	: Collider(pos, name),
	_radius(radius){
	initBitmap();	
}

CircleCollider::CircleCollider(const CircleCollider& other)
	: Collider(other._position, other._name)
	, _bitmap(al_clone_bitmap(other._bitmap))
	, _radius(other._radius){}



CircleCollider::~CircleCollider(){
	al_destroy_bitmap(_bitmap);
}

void CircleCollider::initBitmap(){
	_bitmap = al_create_bitmap(_radius*2, _radius*2);
	al_set_target_bitmap(_bitmap);
	al_clear_to_color(al_map_rgba(0,0,0,0));
	al_draw_circle(_radius, _radius, _radius, al_map_rgb(0, 200, 0), 1);
}

bool CircleCollider::collides(Collider * other) const{
	CircleCollider* circle_ptr = dynamic_cast<CircleCollider*>(other);
	RectCollider* square_ptr = dynamic_cast<RectCollider*>(other);

	if(circle_ptr != NULL){
		CircleCollider circle = *circle_ptr;
		return circleCircleIntersection(_position, _radius, circle.position(), circle.radius());
	}
	if(square_ptr != NULL){
		RectCollider square = *square_ptr;
		return rectCircleIntersection(square.position(), square.size(), _position, _radius);
	}
}

Vector2 CircleCollider::topLeft() const{
	return Vector2(_position.x() - _radius, _position.y() + _radius);
}

ALLEGRO_BITMAP * CircleCollider::getBitmap() const{
	return _bitmap;
}

double CircleCollider::radius() const{
	return _radius;
}
