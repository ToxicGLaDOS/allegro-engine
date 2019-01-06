#include "polygon_collider.h"
#include "geometry.h"
#include "matrix2x2.h"
#include <allegro5/allegro_primitives.h>

PolygonCollider::PolygonCollider(const Transform& trans, std::vector<Vector2> points, const std::string& name, bool fixed/* = false*/)
	: Collider(trans, name)
	, _vertices(points)
	, _static(fixed){
	
	makeBitmap();
}

void PolygonCollider::makeBitmap(){
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
	al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	
	std::vector<Vector2> translatedPoints;
	for(Vector2 p : _vertices){
		Vector2 translated = Vector2((p - Vector2(minx, maxy)).x(), -((p - Vector2(minx, maxy)).y()));
		translatedPoints.push_back(translated);
	}
	for(int i = 0; i < _vertices.size(); i++){
		Vector2 start = translatedPoints[i];
		Vector2 end = translatedPoints[(i + 1) % translatedPoints.size()];
		if(start.x() == 0)
			start = Vector2(start.x() + 1, start.y());
		if(start.y() == 0)
			start = Vector2(start.x(), start.y() + 1);
		if(end.x() == 0)
			end = Vector2(end.x() + 1, end.y());
		al_draw_line(start.x(), start.y(), end.x(), end.y(), al_map_rgb(0, 200, 0), 1);
	}
}

bool PolygonCollider::collides(Collider* other) const{
	Vector2 mtv = minimumTranslationVector(vertices(), other->vertices());
	return polygonPolygonCollision(vertices(), other->vertices());
}

std::vector<Vector2> PolygonCollider::vertices() const{
	std::vector<Vector2> verts = _vertices;

	for(int i = 0; i < verts.size(); i++){
		Vector2 scaled = Matrix2x2::scale(_vertices[i], _transform.scale().x(), _transform.scale().y());
		verts[i] = Matrix2x2::rotate(scaled , _transform.rotation()) + _transform.position();
	}
	
	return verts;
}

ALLEGRO_BITMAP* PolygonCollider::getBitmap() const{
	return _bitmap;
}

