#ifndef ENGINE_H
#define ENGINE_H

#include"collider.h"
#include"camera.h"
#include"input.h"
#include<vector>


class Engine{
	public:
		Engine(int width, int height, unsigned int maxFrameRate);
		~Engine();
		void mainLoop();
		void register_drawable(Drawable * drawable);
		void register_camera(Camera * camera);
		void register_object(Object * object);
		void register_collider(Collider * coll);

		int screenWidth() const;
		int screenHeight() const;
		
		Camera* camera() const;
		Input* input() const;
	protected:
		int _width, _height;
		ALLEGRO_DISPLAY * _display = nullptr; 
		Input* _input;
		std::vector<Object*> _objects;
		std::vector<Collider*> _colliders;
		std::vector<Drawable*> _drawables;
		Camera * _camera = nullptr;
		unsigned int _maxFrameRate;
		bool _running = true;	

		void draw();
		void checkCollisions();
		void cleanup();
		void update();
		void destroyDisplay();

};



#endif 
