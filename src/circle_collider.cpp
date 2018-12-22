#include"circle_collider.h"
#include"square_collider.h"
#include"geometry.h"
#include<string>
#include<allegro5/allegro_primitives.h>




CircleCollider::CircleCollider(Vector2 pos, double radius, std::string name)
	: Collider(pos, name),
	_radius(radius){}


bool CircleCollider::collides(Collider * other){
	CircleCollider* circle_ptr = dynamic_cast<CircleCollider*>(other);
	SquareCollider* square_ptr = dynamic_cast<SquareCollider*>(other);

	if(circle_ptr != NULL){
		CircleCollider circle = *circle_ptr;
		return circleCircleIntersection(_position, _radius, circle.position(), circle.radius());
	}
	if(square_ptr != NULL){
		SquareCollider square = *square_ptr;
		return rectCircleIntersection(square.position(), square.size(), _position, _radius);
	}

}

Vector2 CircleCollider::topLeft(){
	return Vector2(_position.x() - _radius, _position.y() + _radius);
}

ALLEGRO_BITMAP * CircleCollider::makeBitmap(){
	ALLEGRO_BITMAP * bitmap = al_create_bitmap(_radius*2, _radius*2);
	al_set_target_bitmap(bitmap);
	al_clear_to_color(al_map_rgba(0,0,0,0));
	al_draw_circle(_radius, _radius, _radius, al_map_rgb(0, 200, 0), 1);
	return bitmap;


}

double CircleCollider::radius(){
	return _radius;
}
