#include"camera.h"
#include<string>
#include<stdio.h>

Camera::Camera(const Transform& transform, const Vector2& size, const std::string& name)
	:Object(transform, name)
	, _size(size){
	
	_bitmap = al_create_bitmap(_size.x(), _size.y());	
}

Camera::~Camera(){
	al_destroy_bitmap(_bitmap);	
}

void Camera::draw(Drawable* drawable){
	ALLEGRO_BITMAP* drawable_bitmap = drawable->getBitmap();
	al_set_target_bitmap(_bitmap);
	// Negate the y because positive y is down on the screen 
	// but we want a normal coordinate space where up is positive y
	Vector2 position = drawable->transform().position();
	double rotation = drawable->transform().rotation();
	Vector2 scale = drawable->transform().scale();
	int bitmap_width = al_get_bitmap_width(drawable_bitmap);
	int bitmap_height = al_get_bitmap_height(drawable_bitmap);
	
	al_draw_scaled_rotated_bitmap(drawable_bitmap, 
			bitmap_width/2, bitmap_height/2, 
			position.x() - _transform.position().x(), -position.y() + _transform.position().y(), 
			scale.x(), scale.y(), 
			-rotation, 0); // -rotation because allegro rotates clockwise for some reason
	
	
//	al_draw_bitmap(drawable_bitmap, drawable->topLeft().x() - _transform.position().x(), -drawable->topLeft().y() + _transform.position().y(), 0);
//	al_draw_bitmap(drawable_bitmap, position.x() - _transform.position().x(), -position.y() + _transform.position().y(), 0);
}

void Camera::drawGUI(){
	al_set_target_bitmap(_bitmap);
	for(Drawable* guiElement : _guis){
		ALLEGRO_BITMAP* gui_bitmap = guiElement->getBitmap();
		// Draw the gui without regard for the cameras position
		al_draw_bitmap(gui_bitmap, guiElement->topLeft().x(), -guiElement->topLeft().y(), 0);
	}
}

void Camera::attachGUI(Drawable* drawable){
	_guis.push_back(drawable);
	drawable->attach(this);
}


void Camera::update(){
	al_clear_to_color(_background);
}

void Camera::setBackgroundColor(unsigned char r, unsigned char g, unsigned char b){
	_background = al_map_rgb(r,g,b);
}

unsigned char* Camera::background() const{
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

Vector2 Camera::size() const{
	return _size;
}

ALLEGRO_BITMAP * Camera::bitmap() const{
	return _bitmap;
}


