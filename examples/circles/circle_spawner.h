#ifndef CIRCLE_SPAWNER_H
#define CIRCLE_SPAWNER_H

#include"object.h"

class CircleSpawner : public Object{
	public:
		CircleSpawner(const Transform& trans, const std::string& name);
	protected:
		void spawn(Vector2 pos);
		void update();

};

#endif
