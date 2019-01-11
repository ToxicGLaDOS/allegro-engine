#include "prefab.h"

Prefab::Prefab(Object* model, Engine* engine)
	: _model(model)
	, _engine(engine){}

Object* Prefab::instantiate(Transform transform){
	// Calls the copy constructor	
	Object* root = _model->clone();

	root->moveTo(transform.position());
	root->rotateTo(transform.rotation());
	root->scaleTo(transform.scale());
	makeCopy(root, _model->children());
	return root;
}

// Parent is a copy of something in model
// children are the acutal pointers in model
void Prefab::makeCopy(Object* parent, std::vector<Object*> children){
	parent->registerWithEngine(_engine);
	// childPtr is always the actual pointer from model
	for(Object* childPtr : children){
		// Make a copy of the child
		Object* child = childPtr->clone();
	
		// Offset the child relative to the parent
		// The result is that if the child's position is (50, 50) then no matter where you are
		// instantiating the object the child will be (50, 50) relative to the parent
		child->moveTo(parent->transform().position() + child->transform().position());
		child->rotateTo(parent->transform().rotation() + child->transform().rotation());
		child->scaleTo(parent->transform().scale() + child->transform().scale());
		
		// Attach the copy to the parent
		parent->attach(child);
		// Recursive call to do the same to the child
		makeCopy(child, childPtr->children());
	}
}
