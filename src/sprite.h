#ifndef SPRITE_H
#define SPRITE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include "drawable.h"
#include "image_resource.h"

class Sprite : public Drawable{
	public:
		Sprite(const Transform& transform, const ImageResource& image, const std::string& name);		
		ALLEGRO_BITMAP * getBitmap() const;
	protected:
		ImageResource _img;	
};




#endif
