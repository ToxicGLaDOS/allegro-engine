#include"engine.h"
#include"exceptions.h"
#include"geometry.h"
#include<allegro5/allegro5.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<stdio.h>
#include<chrono>
#include<iostream>

Engine::Engine(int width, int height, unsigned int maxFrameRate)
	: _maxFrameRate(maxFrameRate){

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
	if(!al_init_font_addon()){
		throw AllegroInitException("Allegro font addon failed to initalize!");
	}
	if(!al_init_ttf_addon()){
		throw AllegroInitException("Allegro ttf addon failed to initalize!");
	}
	al_set_new_display_option(ALLEGRO_VSYNC, 2, ALLEGRO_SUGGEST);
	al_set_new_display_refresh_rate(maxFrameRate);
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);

	_display = al_create_display(width, height);
	_height = al_get_display_height(_display);
	_width = al_get_display_width(_display);
	_input = new Input();
}

Engine::~Engine(){
	_input->destroy();
	delete _input;
}

void Engine::mainLoop(){
	ALLEGRO_TIMER* timer = al_create_timer(1.000 / _maxFrameRate);
	ALLEGRO_EVENT_QUEUE* timerQueue = al_create_event_queue();
	al_register_event_source(timerQueue, al_get_timer_event_source(timer));
	al_register_event_source(timerQueue, al_get_display_event_source(_display));

	double frametimes[5] = {0, 0, 0, 0, 0};
	int frametimeHead = 0;
	auto start = std::chrono::system_clock::now();

	ALLEGRO_EVENT event;
	al_start_timer(timer);
	while(_running){
		al_wait_for_event(timerQueue, &event);
		switch(event.type){
			case ALLEGRO_EVENT_TIMER:
				{
				update();
				if(_input->keyPressed("escape")){	
					_running = false;
					al_destroy_timer(timer);
					al_destroy_event_queue(timerQueue);
					destroyDisplay();
				}
				cleanup();
				// Timing stuff
				auto end = std::chrono::system_clock::now();
				std::chrono::duration<double> diff = (end-start);
				double averageFramerate = 0;
				frametimes[frametimeHead] = diff.count();
				_deltaTime = diff.count();

				for(int i = 0; i < 5; i++){
					averageFramerate += frametimes[i];
				}
				averageFramerate /= 5;
				_framerate = 1/averageFramerate;
				frametimeHead = (frametimeHead + 1) % 5;
				
				start = std::chrono::system_clock::now();
				break;
				}
			case ALLEGRO_EVENT_DISPLAY_RESIZE:
				//printf("x,y,width,height: (%d, %d, %d, %d)\n",event.display.x,event.display.y,event.display.width,event.display.height);
				al_acknowledge_resize(_display);
				_width = event.display.width;
				_height = event.display.height;

		}
		/*
		std::cout << "The delta time is " << _deltaTime << std::endl;
		std::cout << "The frame rate is " << _framerate << std::endl;
		//std::cout << "Time for this frame is " << diff.count() << " expected time is " << 1.000/_maxFrameRate  << " the difference is " << diff.count() - 1.000/_maxFrameRate << std::endl;
		*/
	}
}

void Engine::draw(){

	for(Drawable * drawable : _drawables){
		_camera->draw(drawable);
	}
	// Draw all colliders onto the camera that want to be drawn
	for(Collider * collider : _colliders){
		if(collider->draw()){
			_camera->draw(collider);
		}
	}
	_camera->drawGUI();


	// Set target to the display
	al_set_target_bitmap(al_get_backbuffer(_display));
	// Draw the cameras view to the display and scale it to the display's size
	al_draw_scaled_bitmap(_camera->bitmap(), 0, 0, _camera->size().x(), _camera->size().y(), 0, 0, _width, _height, 0);
}

void Engine::update(){
	_input->update();
	_camera->update();
	// Clear camera bitmap
	_camera->clearBitmap();


	for(Object * object : _objects){
		object->update();
	}
	for(Drawable* drawable : _drawables){
		al_set_target_bitmap(_camera->bitmap());
		drawable->update();
	}
	for(Collider* collider : _colliders){
		collider->update();
	}
	checkCollisions();
	draw();

	al_flip_display();
}


void Engine::cleanup(){
	_input->clear();
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
		
			// If at least 1 collider is not fixed we have to check for collisions	
			if(!collider1->fixed() || !collider2->fixed()){
				Collision collision = minimumTranslationVector(collider1->vertices(), collider2->vertices());
				Vector2 mtv = collision.mtv;
				bool hit = collision.collided;
				// If mtv != NULL we have a collision
				if(hit){
					// We only need to move stuff around if BOTH colliders are solid
					if(collider1->solid() && collider2->solid()){
						// If 1 collider is fixed we need to move the full distance
						// (we know they aren't both fixed because of the if we used earlier)
						if(collider1->fixed() || collider2->fixed()){
							if(collider1->fixed()){
								collider2->moveBy(mtv * -1);
							}
							else{
								collider1->moveBy(mtv);
							}
						}
						// If both colliders are not fixed, then we can move them both
						// with half the distance in opposite directions
						else{
							// Move both half the distance (in the future this could be scaled by some mass variable)
							collider2->moveBy(mtv * -.5);
							collider1->moveBy(mtv *  .5);
						}
					}
					// Lastly, after collisions have been resolved, we call both callbacks
					collider1->onCollision(collider2);
					collider2->onCollision(collider1);
				}
			}
		}
	}
}

double Engine::framerate() const{
	return _framerate;
}

double Engine::deltaTime() const{
	return _deltaTime;
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

Camera* Engine::camera() const{
	return _camera;
}

Input* Engine::input() const{
	return _input;
}
