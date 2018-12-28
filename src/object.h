#ifndef OBJECT_H
#define OBJECT_H


#include<vector>
#include<string>
#include "vector2.h"

// Forward declaration of engine
class Engine;

class Object{
	public:
		Object(int x_pos, int y_pos, const std::string& name);
		Object(const Vector2& pos, const std::string& name);
		~Object();
		Vector2 position() const;
		void moveTo(const Vector2& pos);	
		void moveBy(const Vector2& by);
		void attach(Object* parent);
		bool isParentOf(Object* child);
		Object* findChildWithName(const std::string& name) const;
		Object* parent() const;
		std::string name() const;
		std::vector <Object*> children() const;
		void setEngine(Engine* engine);
		virtual void update();
	protected:
		Engine* _engine = NULL;
		Vector2  _position;
		std::vector <Object*> _children;
		Object* _parent = NULL;
		std::string _name;
	private:
		void propagate_movement(const Vector2& by);	
};

#endif
