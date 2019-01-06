#include "rect_collider.h"
#include "circle_collider.h"
#include "geometry.h"
#include "matrix2x2.h"
#include <allegro5/allegro_primitives.h>

/*
RectCollider::RectCollider()
	: PolygonCollider(Transform(Vector2(0,0)), "")
	,_size(Vector2(0,0)){
	
	initBitmap();
}
*/
RectCollider::RectCollider(const Transform& transform, const Vector2& size, const std::string& name)
	: PolygonCollider(transform, calcVertices(size), name)
	, _size(size){}
/*
RectCollider::RectCollider(const RectCollider& other)
	: PolygonCollider(other.transform(), other.vertices(), other._name)
	, _bitmap(al_clone_bitmap(other._bitmap))
	, _size(other._size){}
*/
RectCollider::~RectCollider(){
}

std::vector<Vector2> RectCollider::calcVertices(const Vector2& size) const{
	std::vector<Vector2> vertices;	
	vertices.push_back(Vector2(-size.x()/2,  size.y()/2));
	vertices.push_back(Vector2(-size.x()/2, -size.y()/2));
	vertices.push_back(Vector2(size.x()/2,  -size.y()/2));
	vertices.push_back(Vector2(size.x()/2,   size.y()/2));
	return vertices;
}


Vector2 RectCollider::size() const{
	return _size;
}


