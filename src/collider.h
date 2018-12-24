#ifndef COLLIDER_H
#define COLLIDER_H



#include"drawable.h"
#include<string>
#include<allegro5/allegro.h>

class Collider : public Drawable{
	public:
		Collider(const Vector2& pos, const std::string& name);
		virtual bool collides(Collider * other) const = 0;
		void setDraw(bool draw);
		bool draw() const;
	protected:
		bool _draw = false;
};



#endif
