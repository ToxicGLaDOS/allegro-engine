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
		void register_collider(Collider * coll);
		
		int screenWidth() const;
		int screenHeight() const;

		void destroyDisplay();
		Input* input() const;
	private:
		int _width, _height;
		ALLEGRO_DISPLAY * _display; 
		Input* _input;
		std::vector<Object*> _objects;
		std::vector<Collider*> _colliders;
		std::vector<Drawable*> _drawables;
		Camera * _camera;
		
		void draw();
		void checkCollisions();


};



#endif 
