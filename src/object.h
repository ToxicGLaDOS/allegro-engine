#ifndef OBJECT_H
#define OBJECT_H


#include<vector>
#include<string>
#include "vector2.h"
#include "transform.h"

// Forward declaration of engine
class Engine;

class Object{
	public:
		Object(const Transform& pos, const std::string& name);
		Object(const Object& other);
		~Object();
		virtual Object* clone();
		Transform transform() const;
		void moveTo(const Vector2& pos);	
		void moveBy(const Vector2& by);
		void rotateTo(double angle);
		void rotateBy(double angle);
		void scaleTo(const Vector2& scale);
		void scaleBy(const Vector2& scale);
		const Object* root() const;
		void attach(Object* parent);
		bool isParentOf(Object* child);
		Object* findChildWithName(const std::string& name) const;
		Object* parent() const;
		std::string name() const;
		std::vector <Object*> children() const;
		virtual void registerWithEngine(Engine* engine);
		void setEngine(Engine* engine);
		virtual void update();
	protected:
		Engine* _engine = NULL;
		Transform _transform;
		Transform _originalTransform;
		std::vector <Object*> _children;
		Object* _parent = NULL;
		std::string _name;
	private:
		void propagate_scale(const Vector2& scale);
		void propagate_rotation(double angle);
		void propagate_movement(const Vector2& by);	
};

#endif
