#ifndef SPRITE_H
#define SPRITE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include "drawable.h"

class Sprite : public Drawable{
	public:
		Sprite(int x_pos, int y_pos, std::string name, ALLEGRO_BITMAP* image);		
		void draw();
		Vector2 topLeft();
		ALLEGRO_BITMAP * makeBitmap();	
	protected:
		ALLEGRO_BITMAP * _img;	
};




#endif
