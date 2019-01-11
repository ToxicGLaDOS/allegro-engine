#include"mover.h"
#include"engine.h"
#include<iostream>

Mover::Mover(Transform transform, Vector2 size, std::string name, bool solid, bool fixed)
	: RectCollider(transform, size, name, solid, fixed){

}

void Mover::update(){
	Input* input = _engine->input();
	if(input->keyHeld("w"))
		moveBy(Vector2(0,_moveSpeed));
	if(input->keyHeld("s"))
		moveBy(Vector2(0,-_moveSpeed));
	if(input->keyHeld("a"))
		moveBy(Vector2(-_moveSpeed,0));
	if(input->keyHeld("d"))
		moveBy(Vector2(_moveSpeed,0));
	if(input->keyHeld("up"))
		rotateBy(_rotationSpeed);
	if(input->keyHeld("down"))
		rotateBy(-_rotationSpeed);
	if(input->keyHeld("left"))
		scaleBy(Vector2(-_scaleSpeed,-_scaleSpeed));
	if(input->keyHeld("right"))
		scaleBy(Vector2(_scaleSpeed,_scaleSpeed));
}
