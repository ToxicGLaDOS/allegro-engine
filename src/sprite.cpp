#include "sprite.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

Sprite::Sprite(const Vector2& pos, const ImageResource& image, const std::string& name)
	: Drawable(pos, name)
	, _img(image){}


Vector2 Sprite::topLeft() const{
	return _position;
}

ALLEGRO_BITMAP * Sprite::makeBitmap() const{
	return _img.bitmap();
}

