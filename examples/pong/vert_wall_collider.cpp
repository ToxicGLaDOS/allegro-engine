#include"vert_wall_collider.h"
#include"engine.h"


VertWallCollider::VertWallCollider(const Transform& trans, const Vector2& size, const std::string& name, AudioResource* hitSound, Text* score)
	: RectCollider(trans, size, name)
	, _hitSound(hitSound)
	, _score(score){}



void VertWallCollider::onCollision(Collider* other){
	if(other->name() == "Ball collider"){
		int width = _engine->camera()->size().x();
		int height = _engine->camera()->size().y();
		other->parent()->moveTo(Vector2(width/2,-height/2));
		_hitSound->play();
		int score = std::stoi(_score->text());
		_score->setText(std::to_string(score + 1));
	}
}
