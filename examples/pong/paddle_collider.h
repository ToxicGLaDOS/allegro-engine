#ifndef PADDLE_COLLIDER_H
#define PADDLE_COLLIDER_H

#include"collider.h"
#include"square_collider.h"
#include"audio_resource.h"

class PaddleCollider : public SquareCollider{
	public:
		PaddleCollider(const Vector2& pos, const Vector2& size, const std::string& name, AudioResource* hitSound);
		void onCollision(Collider* other);

	private:
		AudioResource* _hitSound;
};



#endif
