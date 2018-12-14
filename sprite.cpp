#include "sprite.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

Sprite::Sprite(int x_pos, int y_pos, ALLEGRO_BITMAP * image)
: Object(x_pos, y_pos){
	img = image;
}


void Sprite::draw(){
	al_draw_bitmap(img, x, y, 0);
}

