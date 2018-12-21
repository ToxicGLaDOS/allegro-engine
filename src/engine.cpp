#include"engine.h"
#include<allegro5/allegro5.h>
#include<stdio.h>

Engine::Engine(int width, int height){
	_display = al_create_display(width, height);
}



void Engine::draw(){
	for(Collider * collider : _colliders){
		ALLEGRO_BITMAP * bitmap = collider->makeBitmap();
		if(bitmap != NULL){
			al_set_target_bitmap(al_get_backbuffer(_display));
			al_draw_bitmap(bitmap, collider->position().x() - _camera->position().x(), collider->position().y() + _camera->position().y(), 0);
		}
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






