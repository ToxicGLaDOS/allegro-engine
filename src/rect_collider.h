#ifndef SQUARE_COLLIDER_H
#define SQUARE_COLLIDER_H

#include "vector2.h"
#include "collider.h"
#include <allegro5/allegro.h>

class RectCollider : public Collider{
	public:
		RectCollider();
		RectCollider(const Transform& transform, const Vector2& size, const std::string& name);
		RectCollider(const RectCollider& other);
		~RectCollider();
		void calcVertices();
		std::vector<Vector2> vertices() const;
		bool collides(Collider * other) const;
		ALLEGRO_BITMAP * getBitmap() const;
		Vector2 size() const;

	private:
		void initBitmap();

		std::vector<Vector2> _vertices;
		ALLEGRO_BITMAP* _bitmap;
		Vector2  _size;
};


#endif
