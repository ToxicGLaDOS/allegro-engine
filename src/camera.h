#ifndef CAMERA_H
#define CAMERA_H

#include"object.h"
#include"vector2.h"
#include"drawable.h"
#include<string>
#include<allegro5/allegro5.h>


class Camera : public Object{

	public:
		Camera(Vector2 pos, Vector2 size, std::string name);
		void draw(Drawable* drawable);
		void clearBitmap();
		void setBackgroundColor(int r, int g, int b);
		unsigned char* background();
		void update();
		Vector2 size();
		ALLEGRO_BITMAP * bitmap();
	protected:
		ALLEGRO_COLOR _background = al_map_rgb(0,0,0);
		ALLEGRO_BITMAP * _bitmap;
		Vector2 _size;


};





#endif
