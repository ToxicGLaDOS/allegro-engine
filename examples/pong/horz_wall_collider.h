#ifndef HORZ_WALL_COLLIDER_H
#define HORZ_WALL_COLLIDER_H

#include"collider.h"
#include"rect_collider.h"

class HorzWallCollider : public RectCollider{
	public:
		HorzWallCollider(const Transform& trans, const Vector2& size, const std::string& name);
		void onCollision(Collider* other);


};


#endif
