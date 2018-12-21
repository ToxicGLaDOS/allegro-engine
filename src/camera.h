#ifndef CAMERA_H
#define CAMERA_H

#include"object.h"
#include"vector2.h"
#include<string>
#include<allegro5/allegro5.h>


class Camera : public Object{

	public:
		Camera(Vector2 pos, Vector2 size, std::string name);
		ALLEGRO_BITMAP render();
	protected:
		Vector2 _size;


};





#endif
