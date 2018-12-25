#include"engine.h"
#include"exceptions.h"
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_primitives.h>
#include<stdio.h>

Engine::Engine(int width, int height)
	: _width(width)
	, _height(height){
	if(!al_init()){
		throw AllegroInitException("Allegro failed to initalize!");
	}
	if(!al_init_image_addon()){
		throw AllegroInitException("Allegro image addon failed to initalize!");
	}
	if(!al_install_audio()){
		throw AllegroInitException("Allegro audio failed to install!");
	}
	if(!al_init_acodec_addon()){
		throw AllegroInitException("Allegro acodec addon failed to initalize!");
	}
	if(!al_init_primitives_addon()){
		throw AllegroInitException("Allegro primitives addon failed to initalize!");
	}
	_display = al_create_display(width, height);
	_input = new Input();
}

Engine::~Engine(){
	_input->destroy();
	delete _input;
}


void Engine::draw(){
	// Clear camera bitmap
	_camera->clearBitmap();

	for(Drawable * drawable : _drawables){
		_camera->draw(drawable);
	}
	// Draw all colliders onto the camera that want to be drawn
	for(Collider * collider : _colliders){
		if(collider->draw()){
			_camera->draw(collider);
		}
	}



	// Set target to the display
	al_set_target_bitmap(al_get_backbuffer(_display));
	// Draw the cameras view to the display and scale it to the display's size
	al_draw_scaled_bitmap(_camera->bitmap(), 0, 0, _camera->size().x(), _camera->size().y(), 0, 0, _width, _height, 0);
}

void Engine::update(){
	_input->update();
	_camera->update();
	for(Object * object : _objects){
		object->update();
	}
	checkCollisions();
	draw();

	_input->clear();
	al_flip_display();
}


void Engine::register_camera(Camera * camera){
	_camera = camera;
	camera->setEngine(this);
}

void Engine::register_object(Object * object){
	_objects.push_back(object);
	object->setEngine(this);
}

void Engine::register_drawable(Drawable * drawable){
	_drawables.push_back(drawable);
	drawable->setEngine(this);
}

void Engine::register_collider(Collider * collider){
	_colliders.push_back(collider);
	collider->setEngine(this);
}

void Engine::checkCollisions(){
	// Iterate through each collider as i
	// then each collider after that one as j
	for(int i = 0; i < _colliders.size(); i++){
		for(int j = i + 1; j < _colliders.size(); j++){
			Collider * collider1 = _colliders[i];
			Collider * collider2 = _colliders[j];
			// If we get a collision we call both callbacks
			if(collider1->collides(collider2)){	
				collider1->onCollision(collider2);
				collider2->onCollision(collider1);
			}
		}
	}
}

int Engine::screenWidth() const{
	return _width;
}

int Engine::screenHeight() const{
	return _height;
}

void Engine::destroyDisplay(){
	al_destroy_display(_display);	
}

Input* Engine::input() const{
	return _input;
}
