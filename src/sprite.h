#ifndef SPRITE_H
#define SPRITE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include "drawable.h"

class Sprite : public Drawable{
	public:
		Sprite(Vector2 pos, ALLEGRO_BITMAP* image, std::string name);		
		void draw();
		Vector2 topLeft();
		ALLEGRO_BITMAP * makeBitmap();	
	protected:
		ALLEGRO_BITMAP * _img;	
};




#endif
