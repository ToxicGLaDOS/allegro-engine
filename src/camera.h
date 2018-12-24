#ifndef CAMERA_H
#define CAMERA_H

#include"object.h"
#include"vector2.h"
#include"drawable.h"
#include<string>
#include<allegro5/allegro5.h>


class Camera : public Object{

	public:
		Camera(const Vector2& pos, const Vector2& size, const std::string& name);
		~Camera();
		void draw(Drawable* drawable);
		void clearBitmap();
		void setBackgroundColor(int r, int g, int b);
		unsigned char* background() const;
		void update();
		Vector2 size() const;
		ALLEGRO_BITMAP * bitmap() const;
	protected:
		ALLEGRO_COLOR _background = al_map_rgb(0,0,0);
		ALLEGRO_BITMAP * _bitmap;
		Vector2 _size;


};





#endif
