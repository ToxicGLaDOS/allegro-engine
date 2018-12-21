#include"engine.h"
#include<allegro5/allegro5.h>
#include<stdio.h>

Engine::Engine(int width, int height)
	: _width(width)
	, _height(height){
	_display = al_create_display(width, height);
}



void Engine::draw(){
	for(Collider * collider : _colliders){
		_camera->draw(collider);
		al_set_target_bitmap(al_get_backbuffer(_display));
		al_draw_scaled_bitmap(_camera->bitmap(), 0, 0, _camera->size().x(), _camera->size().y(), 0, 0, _width, _height, 0);
	}
}

void Engine::update(){
	for(Object * object : _objects){
		object->update();
	}
}

void Engine::register_camera(Camera * camera){
	_camera = camera;
}

void Engine::register_object(Object * object){
	_objects.push_back(object);
}

void Engine::register_collider(Collider * collider){
	_colliders.push_back(collider);
}






