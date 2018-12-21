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

void CircleCollider::draw(ALLEGRO_COLOR draw_color, int width){
	al_draw_circle(_position.x(), _position.y(), _radius, draw_color, width);	
}

double CircleCollider::radius(){
	return _radius;
}
