#ifndef ENGINE_H
#define ENGINE_H

#include"collider.h"
#include"camera.h"
#include<vector>


class Engine{
	public:
		Engine(int width, int height);
		void update();
		void register_camera(Camera * camera);
		void register_object(Object * object);
		void register_collider(Collider * coll, void (*onCollision)(Collider * other));
	private:
		int _width, _height;
		ALLEGRO_DISPLAY * _display; 
		std::vector<Object*> _objects;
		std::vector<Collider*> _colliders;

		// A vector of functions that take Collider pointers
		std::vector<void (*)(Collider*)> _collider_callbacks;
		Camera * _camera;
		
		void draw();
		void checkCollisions();


};



#endif 
