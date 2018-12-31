#include"paddle_collider.h"

#include"ball_motion.h"

PaddleCollider::PaddleCollider(const Transform& trans, const Vector2& size, const std::string& name, AudioResource* hitSound)
	: RectCollider(trans, size, name)
	, _hitSound(hitSound){} 


void PaddleCollider::onCollision(Collider* other){
	if(other->name() == "Ball collider"){
		Object* sibling = other->parent()->findChildWithName("Ball motion");
		if(sibling != NULL){
			BallMotion * ball_motion = (BallMotion*)sibling;
			ball_motion->flipDx();
			_hitSound->play();
		}
	}
}
