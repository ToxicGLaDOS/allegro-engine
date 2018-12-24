#include "object.h"
#include<iostream>
#include "vector2.h"


Object::Object(int x_pos, int y_pos, const std::string& name)
	: _name(name)
	, _position(Vector2(x_pos, y_pos)){}

Object::Object(const Vector2& position, const std::string& name)
	: _name(name)
	, _position(position){}

Vector2 Object::position() const{
	return _position;
}

Object* Object::parent() const{
	return _parent;
}

void Object::move_to(const Vector2& position){
	
	int x_delta = position.x() - _position.x();
	int y_delta = position.y() - _position.y();

	
	move_by(Vector2(x_delta, y_delta));
}

void Object::move_by(const Vector2& by){
	_position = _position + by;
	propagate_movement(by);
}

void Object::attach(Object* parent){
	_parent = parent;
	parent->_children.push_back(this);
}

void Object::setEngine(Engine* engine){
	_engine = engine;
}

Object* Object::findChildWithName(const std::string& name) const{
	for(Object* child : _children){
		if(child->name() == name){
			return child;
		}
	}
	return NULL;
}

std::string Object::name() const{
	return _name;
}

std::vector<Object*> Object::children() const{
	return _children;
}


void Object::propagate_movement(const Vector2& by){
	for(Object * child : _children){
		child->move_by(by);
	}	
}

void Object::update(){
	// To be overridden
}

