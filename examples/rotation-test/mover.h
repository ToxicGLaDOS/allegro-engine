#ifndef MOVER_H
#define MOVER_H

#include"rect_collider.h"

class Mover : public RectCollider{
	public:
		Mover(Transform transform, Vector2 size, std::string name, bool solid = false, bool fixed = false);
		void update();
	private:
		double _moveSpeed = 5, _rotationSpeed = .1, _scaleSpeed = .1;
};

#endif
