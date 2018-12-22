#include "sprite.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

Sprite::Sprite(Vector2 pos, ImageResource image, std::string name)
	: Drawable(pos, name)
	, _img(image){}


Vector2 Sprite::topLeft(){
	return _position;
}

ALLEGRO_BITMAP * Sprite::makeBitmap(){
	return _img.bitmap();
}

