#include "sprite.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

Sprite::Sprite(Vector2 pos, ALLEGRO_BITMAP * image, std::string name)
	: Drawable(pos, name)
	, _img(image){}


void Sprite::draw(){
	al_draw_bitmap(_img, _position.x(), _position.y(), 0);
}

Vector2 Sprite::topLeft(){
	return _position;
}

ALLEGRO_BITMAP * Sprite::makeBitmap(){
	return _img;
}

