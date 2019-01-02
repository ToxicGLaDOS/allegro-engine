#include "polygon.h"
#include <allegro5/allegro_primitives.h>
#include "geometry.h"
#include "input.h"
#include "engine.h"

Polygon::Polygon(const Transform& trans, std::vector<Vector2> points, std::string name)
	: Drawable(Transform(getCenter(points), trans.rotation(), trans.scale()), name)
	, _points(points){	
	

}

Vector2 Polygon::getCenter(std::vector<Vector2> points){
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
	printf("Center: (%f, %f)\n", center.x(), center.y());
	return center;
}

void Polygon::makeBitmap(ALLEGRO_COLOR color){
	Vector2 first = _points[0];
	double minx = first.x(), miny = first.y(), maxx = first.x(), maxy = first.y();
	for(Vector2 v : _points){
		if(v.x() > maxx)
			maxx = v.x();
		if(v.x() < minx)
			minx = v.x();
		if(v.y() > maxy)
			maxy = v.y();
		if(v.y() < miny)
			miny = v.y();
	}
	_topLeft = Vector2(minx, maxy);
	// +1 because the bitmap won't render stuff right on the edge
	_bitmap = al_create_bitmap(maxx - minx, maxy - miny + 1);
	al_set_target_bitmap(_bitmap);
	al_clear_to_color(al_map_rgba(0, 0, 0, 0));
	for(int i = 0; i < _points.size(); i++){
		Vector2 start = _points[i] - Vector2(minx, miny);
		Vector2 end = _points[(i + 1) % _points.size()] - Vector2(minx, miny);
		if(start.x() == 0)
			start = Vector2(start.x() + 1, start.y());
		if(start.y() == 0)
			start = Vector2(start.x(), start.y() + 1);
		al_draw_line(start.x(), start.y(), end.x(), end.y(), color, 1);
	}
}

void Polygon::move(Vector2 dir){
	moveBy(dir);
	std::vector<Vector2> newPoints;
	for(Vector2 v : _points){
		newPoints.push_back(v + dir);
	}
	_points = newPoints;
}

void Polygon::update(){
	if(_name == "poly2"){
		Input* input = _engine->input();
		if(input->keyHeld("w"))
			move(Vector2(0,5));
		if(input->keyHeld("s"))
			move(Vector2(0,-5));
		if(input->keyHeld("a"))
			move(Vector2(-5,0));
		if(input->keyHeld("d"))
			move(Vector2(5,0));
	}
	
	if(_other != NULL){
		if(polygonPolygonCollision(_points, _other->points())){
			makeBitmap(_collide_color);
		}
		else{
			makeBitmap(_noncollide_color);
		}
	}
}

void Polygon::setOther(Polygon* other){
	_other = other;
}

std::vector<Vector2> Polygon::points() const{
	return _points;
}

ALLEGRO_BITMAP* Polygon::getBitmap() const{
	return _bitmap;
}

Vector2 Polygon::topLeft() const{
	return _topLeft;
}

