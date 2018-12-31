#ifndef VERT_WALL_COLLIDER_H
#define VERT_WALL_COLLIDER_H

#include"collider.h"
#include"rect_collider.h"
#include"audio_resource.h"
#include"text.h"

class VertWallCollider : public RectCollider{
	public:
		VertWallCollider(const Transform& trans, const Vector2& size, const std::string& name, AudioResource* hitSound, Text* score);
		void onCollision(Collider* other);
	private:
		AudioResource* _hitSound;
		Text* _score;
};



#endif
