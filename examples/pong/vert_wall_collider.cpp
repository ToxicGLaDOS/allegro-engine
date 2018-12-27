#include"vert_wall_collider.h"
#include"engine.h"


VertWallCollider::VertWallCollider(const Vector2& pos, const Vector2& size, const std::string& name, AudioResource* hitSound)
	: SquareCollider(pos, size, name)
	, _hitSound(hitSound){}



void VertWallCollider::onCollision(Collider* other){
	if(other->name() == "Ball collider"){
		int width = _engine->screenWidth();
		int height = _engine->screenHeight();
		other->parent()->move_to(Vector2(width/2,-height/2));
		_hitSound->play();
	}
}
