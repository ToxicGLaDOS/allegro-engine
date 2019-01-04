#include"circle_collider.h"
#include"rect_collider.h"
#include"geometry.h"
#include"matrix2x2.h"
#include<string>
#include<allegro5/allegro_primitives.h>
#include<math.h>



CircleCollider::CircleCollider(const Transform& transform, double radius, const std::string& name)
	: Collider(transform, name),
	_radius(radius){

	
	initBitmap();
}

CircleCollider::CircleCollider(const CircleCollider& other)
	: Collider(other.transform(), other._name)
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

void CircleCollider::calcVertices(){
	_vertices.clear();
	
	double twopi = 2*M_PI;
	int resolution = 20;
	Vector2 pos = _transform.position();
	for(int i = 0; i < resolution; i++){
		double t = (i/(double)resolution) * twopi;
		_vertices.push_back(Vector2(_radius * cos(t), _radius * sin(t)));
	}
	for(int i = 0; i < _vertices.size(); i++){
		Vector2 scaled = Matrix2x2::scale(_vertices[i], _transform.scale().x(), _transform.scale().y());
		_vertices[i] = Matrix2x2::rotate(scaled , _transform.rotation()) + _transform.position();
	}

}

std::vector<Vector2> CircleCollider::vertices() const{
	return _vertices;
}

bool CircleCollider::collides(Collider * other) const{
	return polygonPolygonCollision(_vertices, other->vertices());
}

ALLEGRO_BITMAP * CircleCollider::getBitmap() const{
	return _bitmap;
}

double CircleCollider::radius() const{
	return _radius;
}
