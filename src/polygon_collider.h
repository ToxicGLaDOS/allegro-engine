#ifndef POLYGON_COLLIDER_H
#define POLYGON_COLLIDER_H

#include"collider.h"
#include<vector>

class PolygonCollider : public Collider{
	public: 
		PolygonCollider(const Transform& trans, std::vector<Vector2> points, const std::string& name);
		bool collides(Collider* other) const;
		std::vector<Vector2> vertices() const;
		void calcVertices();
		ALLEGRO_BITMAP* getBitmap() const;
	protected:	
		void makeBitmap();
		
		std::vector<Vector2> _original_vertices;
		std::vector<Vector2> _vertices;
		ALLEGRO_BITMAP* _bitmap;
};

#endif
