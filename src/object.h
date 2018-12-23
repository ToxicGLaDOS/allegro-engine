#ifndef OBJECT_H
#define OBJECT_H


#include<vector>
#include<string>
#include "vector2.h"

// Forward declaration of engine
class Engine;

class Object{
	public:
		Object(int x_pos, int y_pos, std::string name);
		Object(Vector2 pos, std::string name);
		Vector2 position();
		void move_to(Vector2 pos);	
		void move_by(Vector2 by);
		void attach(Object * parent);
		Object* findChildWithName(std::string name);
		Object* parent();
		std::string name();
		std::vector <Object*> get_children();
		void setEngine(Engine* engine);
		virtual void update();
	protected:
		Engine* _engine;
		Vector2  _position;
		std::vector <Object*> _children;
		Object* _parent;
		std::string _name;	
	private:
		void propagate_movement(Vector2 by);	
};

#endif
