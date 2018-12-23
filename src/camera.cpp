#include"camera.h"
#include<string>
#include<stdio.h>

Camera::Camera(Vector2 pos, Vector2 size, std::string name)
	:Object(pos, name)
	, _size(size){
	
	_bitmap = al_create_bitmap(_size.x(), _size.y());	
}


void Camera::draw(Drawable* drawable){
	ALLEGRO_BITMAP * drawable_bitmap = drawable->makeBitmap();
	al_set_target_bitmap(_bitmap);
	// Negate the y because positive y is down on the screen 
	// but we want a normal coordinate space where up is positive y
	al_draw_bitmap(drawable_bitmap, drawable->topLeft().x() - _position.x(), -drawable->topLeft().y() + _position.y(), 0);

}

void Camera::update(){
	al_clear_to_color(_background);
}

void Camera::setBackgroundColor(int r, int g, int b){
	// TODO: bounds checking on r g b
	_background = al_map_rgb(r,g,b);
}

unsigned char* Camera::background(){
	unsigned char r,g,b;
	al_unmap_rgb(_background, &r, &g, &b);
	unsigned char* array = new unsigned char(r);
	array++;
	*array = g;
	array++;
	*array = b;
	array--;
	array--;
	return array;
}

void Camera::clearBitmap(){
	al_set_target_bitmap(_bitmap);
	al_clear_to_color(al_map_rgba(0,0,0,0));
}

Vector2 Camera::size(){
	return _size;
}

ALLEGRO_BITMAP * Camera::bitmap(){
	return _bitmap;
}


