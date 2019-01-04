#ifndef DRAWABLE_H
#define DRAWABLE_H

#include"object.h"
#include"vector2.h"
#include<string>
#include<allegro5/allegro.h>


class Drawable : public Object{
	public:
		Drawable(const Transform& transform, const std::string& name);
		virtual ALLEGRO_BITMAP * getBitmap() const = 0;
	protected:
};


#endif
