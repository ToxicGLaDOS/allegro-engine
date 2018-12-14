#include "object.h"
#include<iostream>

Object::Object(int x_pos, int y_pos, std::string name){
	_x = x_pos;
	_y = y_pos;
	_name = name;
}

int* Object::get_location(){
	return new int[2] {_x,_y};
}

void Object::move_to(int x_pos, int y_pos){
	int x_delta = x_pos - _x;
	int y_delta = y_pos - _y;
	
	move_by(x_delta, y_delta);
}

void Object::move_by(int x_by, int y_by){
	_x += x_by;
	_y += y_by;
	propagate_movement(x_by, y_by);
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


void Object::propagate_movement(int x_by, int y_by){
	for(Object * child : _children){
		child->move_by(x_by, y_by);
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
