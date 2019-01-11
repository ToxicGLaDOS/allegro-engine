#include "object.h"
#include<iostream>
#include "vector2.h"
#include "exceptions.h"
#include "engine.h"
#include "matrix2x2.h"

Object::Object(const Transform& transform, const std::string& name)
	: _name(name)
	, _transform(transform)
	, _originalTransform(transform){}

Object::Object(const Object& other)
	: _name(other.name())
	, _transform(other.transform())
	, _engine(other._engine)
	, _originalTransform(other.transform()){}

Object* Object::clone(){
	// Calls copy ctor
	return new Object(*this);
}

Object::~Object(){
	for(Object * obj : _children){
		obj->attach(NULL);
	}
}

Transform Object::transform() const{
	return _transform;
}

Object* Object::parent() const{
	return _parent;
}

const Object* Object::root() const{
	Object* parent = _parent;
	const Object* cur = this;
	while(parent != NULL){
		parent = parent->parent();
		cur = cur->parent();
	}
	return cur;
}

void Object::moveTo(const Vector2& position){
	
	double x_delta = position.x() - _transform.position().x();
	double y_delta = position.y() - _transform.position().y();
	
	moveBy(Vector2(x_delta, y_delta));
}

void Object::moveBy(const Vector2& by){
	_transform.setPosition(_transform.position() + by);
	propagate_movement(by);
}

void Object::rotateTo(double angle){
	double delta = angle - _transform.rotation();
	rotateBy(delta);
}

void Object::rotateBy(double angle){
	_transform.setRotation(_transform.rotation() + angle);
	propagate_rotation(angle);
}

void Object::scaleTo(const Vector2& scale){
	double x_delta = scale.x() - _transform.scale().x();
	double y_delta = scale.y() - _transform.scale().y();

	scaleBy(Vector2(x_delta, y_delta));
}

void Object::scaleBy(const Vector2& scale){
	_transform.setScale(_transform.scale() + scale);
	propagate_scale(scale);
}

void Object::attach(Object* parent){
	if(parent == NULL){
		_parent = nullptr;
	}
	else{
		// If we are already the parent of the thing we are attaching to we throw an error
		// Even if we are grandparents or great grandparents, etc. this still will throw an error
		// We do this because if there is a cycle in the parent structure any movement will propagate cyclicly forever
		if(isParentOf(parent)){
			std::string error = "Failed to attach object with name ";
			error.append(_name);
			error.append(" to object with name ");
			error.append(parent->name());
			error.append(" because ");
			error.append(_name);
			error.append(" is a parent of ");
			error.append(parent->name());
			throw AttachToChildException(error);
		}
		else if(parent == this){
			// TODO: Change this to a better error type
			std::string error = "Cannot attach object to itself!";
			throw AttachToChildException(error);
		}
		_parent = parent;
		parent->_children.push_back(this);

	}
}

bool Object::isParentOf(Object* child){
	Object* parent = child->parent();
	while(parent != NULL){
		if(parent == this){
			return true;
		}
		else{
			parent = parent->parent();
		}
	}
	return false;
}


void Object::registerWithEngine(Engine* engine){
	engine->register_object(this);
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

void Object::propagate_scale(const Vector2& scale){
	for(Object* child : _children){
		// We calculate the change in rotation from to original rotation
		double deltaRotation = _transform.rotation() - _originalTransform.rotation();
		// We rotate the difference in position between where the child is and the anchor (root in this case) deltaRotation radians
		// This effectively changes the coordinate system to be centered at the root, thereby making it the "anchor"
		Vector2 rotatedPosition = Matrix2x2::rotate(child->_originalTransform.position() - root()->_originalTransform.position(), deltaRotation);
		// Then we scale the rotated position up or down the correct amount
		// and add back the position of the root to counter act the change of coordinate system thing we did on the last line
		Vector2 newPosition = Matrix2x2::scale(rotatedPosition,
						       child->transform().scale().x() + scale.x(), child->transform().scale().y() + scale.y()) 
						       + root()->transform().position();
		child->moveTo(newPosition);
		child->scaleBy(scale);
	}
}

void Object::propagate_rotation(double angle){
	for(Object* child : _children){
		Vector2 newPosition = Matrix2x2::rotate(child->transform().position() - _transform.position(), angle) + transform().position();
		child->moveTo(newPosition);
		child->rotateBy(angle);
	}
}

void Object::propagate_movement(const Vector2& by){
	for(Object * child : _children){
		child->moveBy(by);
	}	
}

void Object::update(){
	// To be overridden
}

