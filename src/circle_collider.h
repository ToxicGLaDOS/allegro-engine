#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include"collider.h"
#include"vector2.h"
#include<string>
#include<allegro5/allegro5.h>

class CircleCollider : public Collider{


	public:
		CircleCollider(const Vector2& position, double radius, const std::string& name);
		CircleCollider(const CircleCollider& other);
		~CircleCollider();
		double radius() const;
		bool collides(Collider * other) const;
		Vector2 topLeft() const;
		ALLEGRO_BITMAP * makeBitmap() const;
	private:
		void initBitmap();

		ALLEGRO_BITMAP* _bitmap;
		double _radius;



};



#endif
