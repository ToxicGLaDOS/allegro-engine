#ifndef POLYGON_H
#define POLYGON_H

#include "drawable.h"


class Polygon : public Drawable{
	public:
		Polygon(const Transform& trans, std::vector<Vector2> points, std::string name);
		ALLEGRO_BITMAP* getBitmap() const;
		Vector2 topLeft() const;
		Vector2 bitmapCenter() const;
		void transformPoints();
		Vector2 getCenter(std::vector<Vector2> points);
		void update();
		void move(Vector2 dir);
		void makeBitmap(ALLEGRO_COLOR color);
		std::vector<Vector2> points() const;
		void setOther(Polygon* other);
	protected:
		Vector2 _topLeft;	
		Polygon* _other = NULL;
		ALLEGRO_BITMAP* _bitmap;
		std::vector<Vector2> _points, _base_points;
		ALLEGRO_COLOR _collide_color = al_map_rgb(255,0,0);
		ALLEGRO_COLOR _noncollide_color= al_map_rgb(0,255,0);
};


#endif
