#ifndef ENGINE_H
#define ENGINE_H

#include"collider.h"
#include"camera.h"
#include<vector>


class Engine{
	public:
		Engine(int width, int height);
		void draw();
		void update();
		void register_camera(Camera * camera);
		void register_object(Object * object);
		void register_collider(Collider * coll);
	private:
		int _width, _height;
		ALLEGRO_DISPLAY * _display; 
		std::vector<Object*> _objects;
		std::vector<Collider*> _colliders;
		Camera * _camera;


};



#endif 
