#ifndef OBJECT_H
#define OBJECT_H


#include<vector>
#include<string>
#include "vector2.h"

// Forward declaration of engine
class Engine;

class Object{
	public:
		// TODO: Detach childen in destructor or destroy children with it
		Object(int x_pos, int y_pos, const std::string& name);
		Object(const Vector2& pos, const std::string& name);
		Vector2 position() const;
		void move_to(const Vector2& pos);	
		void move_by(const Vector2& by);
		void attach(Object* parent);
		Object* findChildWithName(const std::string& name) const;
		Object* parent() const;
		std::string name() const;
		std::vector <Object*> children() const;
		void setEngine(Engine* engine);
		virtual void update();
	protected:
		Engine* _engine;
		Vector2  _position;
		std::vector <Object*> _children;
		Object* _parent;
		std::string _name;
	private:
		void propagate_movement(const Vector2& by);	
};

#endif
