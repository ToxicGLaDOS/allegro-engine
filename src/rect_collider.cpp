#include "rect_collider.h"
#include "circle_collider.h"
#include "geometry.h"
#include "matrix2x2.h"
#include <allegro5/allegro_primitives.h>


RectCollider::RectCollider()
	: Collider(Transform(Vector2(0,0), 0, Vector2(1,1)), "")
	,_size(Vector2(0,0)){
	
	initBitmap();
}

RectCollider::RectCollider(const Transform& transform, const Vector2& size, const std::string& name)
	: Collider(transform, name)
	, _size(size){
	
	initBitmap();
}

RectCollider::RectCollider(const RectCollider& other)
	: Collider(other.transform(), other._name)
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

void RectCollider::calcVertices(){
	Vector2 pos = _transform.position();
	_vertices.clear();
	_vertices.push_back(Vector2(-_size.x()/2,  _size.y()/2));
	_vertices.push_back(Vector2(-_size.x()/2, -_size.y()/2));
	_vertices.push_back(Vector2(_size.x()/2,  -_size.y()/2));
	_vertices.push_back(Vector2(_size.x()/2,   _size.y()/2));
	for(int i = 0; i < _vertices.size(); i++){
		Vector2 scaled = Matrix2x2::scale(_vertices[i], _transform.scale().x(), _transform.scale().y());
		_vertices[i] = Matrix2x2::rotate(scaled , _transform.rotation()) + _transform.position();
	}
	//printf("%s: (%f, %f), (%f, %f), (%f, %f), (%f, %f)\n", _name.c_str(), _vertices[0].x(), _vertices[0].y(), _vertices[1].x(), _vertices[1].y(), _vertices[2].x(), _vertices[2].y(), _vertices[3].x(), _vertices[3].y());
}

std::vector<Vector2> RectCollider::vertices() const{
	return _vertices;
}


bool RectCollider::collides(Collider * other) const{
	return polygonPolygonCollision(vertices(), other->vertices());
}

Vector2 RectCollider::topLeft() const{
	return _transform.position();
}

ALLEGRO_BITMAP * RectCollider::getBitmap() const{
	return _bitmap;
}

Vector2 RectCollider::size() const{
	return _size;
}


