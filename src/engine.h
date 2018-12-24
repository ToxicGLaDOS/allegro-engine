#ifndef ENGINE_H
#define ENGINE_H

#include"collider.h"
#include"camera.h"
#include"input.h"
#include<vector>


class Engine{
	public:
		Engine(int width, int height);
		~Engine();
		void update();
		void register_drawable(Drawable * drawable);
		void register_camera(Camera * camera);
		void register_object(Object * object);
		void register_collider(Collider * coll, void (*onCollision)(Collider * other));
		void destroyDisplay();
		Input* input() const;
	private:
		int _width, _height;
		ALLEGRO_DISPLAY * _display; 
		Input* _input;
		std::vector<Object*> _objects;
		std::vector<Collider*> _colliders;
		std::vector<Drawable*> _drawables;
		// A vector of functions that take Collider pointers
		std::vector<void (*)(Collider*)> _collider_callbacks;
		Camera * _camera;
		
		void draw();
		void checkCollisions();


};



#endif 
