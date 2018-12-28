#include"p2_paddle.h"
#include"engine.h"
#include<stdio.h>

P2Paddle::P2Paddle(const Vector2& pos, float speed, const ImageResource& image, const std::string& name)
	: Sprite(pos, image, name)
	, _speed(speed){}



void P2Paddle::update(){
		Input input = *_engine->input();
		if(input.keyHeld("up")){
			moveBy(Vector2(0, _speed));
		}
		else if(input.keyHeld("down")){
			moveBy(Vector2(0, -_speed));
		}
	
}
