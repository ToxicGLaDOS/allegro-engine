#ifndef SPRITE_H
#define SPRITE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include "drawable.h"
#include "image_resource.h"

class Sprite : public Drawable{
	public:
		Sprite(Vector2 pos, ImageResource image, std::string name);		
		Vector2 topLeft();
		ALLEGRO_BITMAP * makeBitmap();	
	protected:
		ImageResource _img;	
};




#endif
