#ifndef COLLIDER_H
#define COLLIDER_H



#include"drawable.h"
#include<string>
#include<allegro5/allegro.h>

class Collider : public Drawable{
	public:
		Collider(const Transform& transform, const std::string& name, bool solid = false, bool fixed = false);
		virtual bool collides(Collider * other) const = 0;
		virtual std::vector<Vector2> vertices() const = 0;
		
		void registerWithEngine(Engine* engine);
		// Called once every frame by engine
		// right before collisions
		virtual void onCollision(Collider* other);
		void setDraw(bool draw);
		bool draw() const;
		bool solid() const;
		bool fixed() const;
	protected:
		bool _solid;
		bool _fixed;
		bool _draw = false;
};



#endif
