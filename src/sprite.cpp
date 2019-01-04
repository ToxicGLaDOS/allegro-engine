#include "sprite.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

Sprite::Sprite(const Transform& transform, const ImageResource& image, const std::string& name)
	: Drawable(transform, name)
	, _img(image){}


ALLEGRO_BITMAP * Sprite::getBitmap() const{
	return _img.bitmap();
}

