#ifndef SQUARE_COLLIDER_H
#define SQUARE_COLLIDER_H

#include "vector2.h"
#include "collider.h"
#include "polygon_collider.h"
#include <allegro5/allegro.h>

class RectCollider : public PolygonCollider{
	public:
		//RectCollider();
		RectCollider(const Transform& transform, const Vector2& size, const std::string& name);
		//RectCollider(const RectCollider& other);
		~RectCollider();
		Vector2 size() const;

	private:
		std::vector<Vector2> calcVertices(const Vector2& size) const;
		Vector2  _size;
};


#endif
