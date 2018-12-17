#include "sprite.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

Sprite::Sprite(int x_pos, int y_pos, std::string name, ALLEGRO_BITMAP * image)
	: Object(x_pos, y_pos, name)
	, _img(image){}


void Sprite::draw(){
	al_draw_bitmap(_img, _position.x(), _position.y(), 0);
}

