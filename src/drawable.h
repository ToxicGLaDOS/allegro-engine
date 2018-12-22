#ifndef DRAWABLE_H
#define DRAWABLE_H

#include"object.h"
#include"vector2.h"
#include<string>
#include<allegro5/allegro.h>


class Drawable : public Object{
	public:
		Drawable(Vector2 pos, std::string name);
		virtual ALLEGRO_BITMAP * makeBitmap() = 0;
		virtual Vector2 topLeft() = 0;
};


#endif
