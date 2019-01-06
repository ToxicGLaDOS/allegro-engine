#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include"collider.h"
#include"vector2.h"
#include"polygon_collider.h"
#include<string>
#include<allegro5/allegro5.h>

class CircleCollider : public PolygonCollider{


	public:
		CircleCollider(const Transform& transform, double radius, const std::string& name, bool solid = false, bool fixed = false);
		CircleCollider(const CircleCollider& other);
		~CircleCollider();
		double radius() const;
	private:
		std::vector<Vector2> calcVertices(double radius) const;
		
		double _radius;



};



#endif
