#ifndef COLLIDER_H
#define COLLIDER_H



#include"drawable.h"
#include<string>
#include<allegro5/allegro.h>

class Collider : public Drawable{
	public:
		Collider(Vector2 pos, std::string name);
		virtual bool collides(Collider * other) = 0;
		void setDraw(bool draw);
		bool draw();
	protected:
		bool _draw = false;
};



#endif
