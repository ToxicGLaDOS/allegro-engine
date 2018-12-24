#ifndef DRAWABLE_H
#define DRAWABLE_H

#include"object.h"
#include"vector2.h"
#include<string>
#include<allegro5/allegro.h>


class Drawable : public Object{
	public:
		Drawable(const Vector2& pos, const std::string& name);
		virtual ALLEGRO_BITMAP * makeBitmap() const = 0;
		virtual Vector2 topLeft() const = 0;
	protected:
};


#endif
