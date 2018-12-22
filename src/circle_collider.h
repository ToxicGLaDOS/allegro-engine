#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include"collider.h"
#include"vector2.h"
#include<string>
#include<allegro5/allegro5.h>

class CircleCollider : public Collider{


	public:
		CircleCollider(Vector2 position, double radius, std::string name);
		double radius();
		bool collides(Collider * other);
		void draw(ALLEGRO_COLOR color, int width);
		Vector2 topLeft();
		ALLEGRO_BITMAP * makeBitmap();
	private:
		double _radius;



};



#endif
