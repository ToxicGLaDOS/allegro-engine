#include "polygon_collider.h"
#include "geometry.h"
#include "matrix2x2.h"
#include <allegro5/allegro_primitives.h>

PolygonCollider::PolygonCollider(const Transform& trans, std::vector<Vector2> points, const std::string& name)
	: Collider(Transform(trans.position(), trans.rotation(), trans.scale()), name)
	, _vertices(points)
	, _original_vertices(points){
	
	Vector2 first = _vertices[0];
	double minx = first.x(), miny = first.y(), maxx = first.x(), maxy = first.y();
	for(Vector2 v : _vertices){
		if(v.x() > maxx)
			maxx = v.x();
		if(v.x() < minx)
			minx = v.x();
		if(v.y() > maxy)
			maxy = v.y();
		if(v.y() < miny)
			miny = v.y();
	}
	// +1 because the bitmap won't render stuff right on the edge
	_bitmap = al_create_bitmap(maxx - minx, maxy - miny + 1);
	al_set_target_bitmap(_bitmap);
	
	al_clear_to_color(al_map_rgba(0, 0, 0, 255));
	ALLEGRO_COLOR color = al_map_rgb(0, 200, 0);
	for(int i = 0; i < _vertices.size(); i++){
		Vector2 start = _vertices[i] - Vector2(minx, miny);
		//printf("Start: (%f, %f)\n",start.x(),start.y());
		Vector2 end = _vertices[(i + 1) % _vertices.size()] - Vector2(minx, miny);
		if(start.x() == 0)
			start = Vector2(start.x() + 1, start.y());
		if(start.y() == 0)
			start = Vector2(start.x(), start.y() + 1);
		if(end.x() == 0)
			end = Vector2(end.x() + 1, end.y());
		al_draw_line(start.x(), start.y(), end.x(), end.y(), color, 10);
	}
}

Vector2 PolygonCollider::calcPosition(std::vector<Vector2> points){
	Vector2 first = points[0];
	double minx = first.x(), miny = first.y(), maxx = first.x(), maxy = first.y();
	for(Vector2 v : points){
		if(v.x() > maxx)
			maxx = v.x();
		if(v.x() < minx)
			minx = v.x();
		if(v.y() > maxy)
			maxy = v.y();
		if(v.y() < miny)
			miny = v.y();
	}
	Vector2 center = Vector2((maxx + minx) / 2, (maxy + miny) /2);
	return center;
}

bool PolygonCollider::collides(Collider* other) const{
	return polygonPolygonCollision(vertices(), other->vertices());
}

std::vector<Vector2> PolygonCollider::vertices() const{
	return _vertices;
}

void PolygonCollider::calcVertices(){
	for(int i = 0; i < _vertices.size(); i++){
		_vertices[i] = Matrix2x2::rotate(_original_vertices[i] - _transform.position(), _transform.rotation()) + _transform.position();
	}
}

ALLEGRO_BITMAP* PolygonCollider::getBitmap() const{
	return _bitmap;
}

Vector2 PolygonCollider::topLeft() const{
	return Vector2(0,0);
}
