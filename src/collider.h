#ifndef COLLIDER_H
#define COLLIDER_H



#include"object.h"
#include<string>

class Collider : public Object{
	public:
		Collider(Vector2 pos, std::string name);
		virtual bool collides(Collider * other) = 0;
		virtual void draw() = 0;
	private:


};



#endif
