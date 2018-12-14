#ifndef SPRITE_H
#define SPRITE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include "object.h"

class Sprite : Object{
	public:
		
		ALLEGRO_BITMAP * img;	

		Sprite(int x_pos, int y_pos, ALLEGRO_BITMAP* image);		
		void draw();
	private:
		
};




#endif
