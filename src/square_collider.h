#ifndef SQUARE_COLLIDER_H
#define SQUARE_COLLIDER_H

#include "vector2.h"
#include "collider.h"
#include <allegro5/allegro.h>

class SquareCollider : public Collider{
	public:
		SquareCollider();
		SquareCollider(Vector2 position, Vector2 size, std::string name);
		bool collides(Collider * other);
		void draw(ALLEGRO_COLOR color, int width);
		Vector2 topLeft();
		ALLEGRO_BITMAP * makeBitmap();
		Vector2 size();

	private:
		bool _draw = false;
		Vector2  _size;
};


#endif
