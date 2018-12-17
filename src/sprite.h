#ifndef SPRITE_H
#define SPRITE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include "object.h"

class Sprite : public Object{
	public:
		
		ALLEGRO_BITMAP * _img;	

		Sprite(int x_pos, int y_pos, std::string name, ALLEGRO_BITMAP* image);		
		void draw();
	private:
		
};




#endif
