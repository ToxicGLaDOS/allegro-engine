#include "object.h"
#include<iostream>
#include "vector2.h"


Object::Object(int x_pos, int y_pos, std::string name)
	: _name(name)
	, _position(Vector2(x_pos, y_pos)){}

Object::Object(Vector2 position, std::string name)
	: _name(name)
	, _position(position){}

Vector2 Object::position(){
	return _position;
}

void Object::move_to(Vector2 position){
	
	int x_delta = position.x() - _position.x();
	int y_delta = position.y() - _position.y();

	
	move_by(Vector2(x_delta, y_delta));
}

void Object::move_by(Vector2 by){
	_position = _position + by;
	propagate_movement(by);
}

void Object::attach(Object *parent){
	_parent = parent;
	parent->_children.push_back(this);
}

std::string Object::get_name(){
	return _name;
}

std::vector<Object*> Object::get_children(){
	return _children;
}


void Object::propagate_movement(Vector2 by){
	for(Object * child : _children){
		child->move_by(by);
	}	
}

/*
int main(){
	Object obj = Object(100,100);

	int x,y;

	int* pos;
	pos = obj.get_location();


	x = pos[0];
	y = pos[1];

	printf("X is %d, Y is %d\n", x, y);

	return 0;
}
*/
