#include"ball_motion.h"
#include"stdio.h"

BallMotion::BallMotion(double dx, double dy, std::string name)
	: Object(Vector2(0,0), name)
	  ,_dx(dx)
	  ,_dy(dy){}

void BallMotion::update(){
	_parent->move_by(Vector2(_dx, _dy));
}

void BallMotion::flipDx(){
	_dx = -_dx;
}

void BallMotion::flipDy(){
	_dy = -_dy;
}

