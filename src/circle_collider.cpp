#include"circle_collider.h"
#include"rect_collider.h"
#include"geometry.h"
#include"matrix2x2.h"
#include<string>
#include<allegro5/allegro_primitives.h>
#include<math.h>



CircleCollider::CircleCollider(const Transform& transform, double radius, const std::string& name, bool fixed/* = false*/)
	: PolygonCollider(transform, calcVertices(radius), name, fixed),
	_radius(radius){}

/*
CircleCollider::CircleCollider(const CircleCollider& other)
	: PolygonCollider(other.transform(), calcVertices(other.radius()), other._name)
	, _bitmap(al_clone_bitmap(other._bitmap))
	, _radius(other._radius){}
*/


CircleCollider::~CircleCollider(){}

std::vector<Vector2> CircleCollider::calcVertices(double radius) const{
	std::vector<Vector2> vertices;

	double twopi = 2*M_PI;
	int resolution = 20;
	Vector2 pos = _transform.position();
	for(int i = 0; i < resolution; i++){
		double t = (i/(double)resolution) * twopi;
		vertices.push_back(Vector2(radius * cos(t), radius * sin(t)));
	}
	return vertices;
}

double CircleCollider::radius() const{
	return _radius;
}
