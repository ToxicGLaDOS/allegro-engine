#ifndef VERT_WALL_COLLIDER_H
#define VERT_WALL_COLLIDER_H

#include"collider.h"
#include"square_collider.h"

class VertWallCollider : public SquareCollider{
	public:
		VertWallCollider(const Vector2& pos, const Vector2& size, const std::string& name);
		void onCollision(Collider* other);
};



#endif
