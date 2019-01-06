#include "circle_spawner.h"
#include "circle_collider.h"
#include "engine.h"
#include <cstdlib>
#include "gravity.h"

CircleSpawner::CircleSpawner(const Transform& trans, const std::string& name)
	: Object(trans, name){}


void CircleSpawner::spawn(Vector2 position){
	// Random between 100-200
	int radius = rand() % 100 + 20;
	Gravity* gravity = new Gravity(Transform(position), "newGravity");
	CircleCollider* cc = new CircleCollider(Transform(position), radius, "newCollider", true, false);
	cc->attach(gravity);
	_engine->register_object(gravity);
	_engine->register_collider(cc);
	cc->setDraw(true);
}

void CircleSpawner::update(){
	Input* input = _engine->input();
	if(input->mouseButtonPressed(0)){
		Vector2 mousePos = input->mousePosition();
		Camera* camera = _engine->camera();
		spawn(camera->cameraToWorldSpace(mousePos));
	}
}
