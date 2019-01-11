#include"drawable.h"
#include"engine.h"

Drawable::Drawable(const Transform& transform, const std::string& name)
	:Object(transform, name){}

Drawable::Drawable(const Drawable& other)
	: Object(other){
}

void Drawable::registerWithEngine(Engine* engine){
	engine->register_drawable(this);
}
