#ifndef PADDLE_COLLIDER_H
#define PADDLE_COLLIDER_H

#include"collider.h"
#include"rect_collider.h"
#include"audio_resource.h"

class PaddleCollider : public RectCollider{
	public:
		PaddleCollider(const Transform& trans, const Vector2& size, const std::string& name, AudioResource* hitSound);
		void onCollision(Collider* other);

	private:
		AudioResource* _hitSound;
};



#endif
