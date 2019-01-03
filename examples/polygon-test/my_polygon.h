#ifndef MY_POLYGON_H
#define MY_POLYGON_H

#include"polygon_collider.h"
#include<vector>


class MyPolygon : public PolygonCollider{
	public:
		MyPolygon(const Transform& trans, std::vector<Vector2> points, const std::string& name);
		void onCollision(Collider* other);
		void update();
	private:
		void move(Vector2 dir);
};


#endif
