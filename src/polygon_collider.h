#ifndef POLYGON_COLLIDER_H
#define POLYGON_COLLIDER_H

#include"collider.h"
#include<vector>

class PolygonCollider : public Collider{
	public: 
		PolygonCollider(const Transform& trans, std::vector<Vector2> points, const std::string& name, bool solid = false, bool fixed = false);
		virtual Object* clone();
		bool collides(Collider* other) const;
		std::vector<Vector2> vertices() const;
		ALLEGRO_BITMAP* getBitmap() const;
	protected:	
		void makeBitmap();
		
		const std::vector<Vector2> _vertices;
		ALLEGRO_BITMAP* _bitmap;
};

#endif
