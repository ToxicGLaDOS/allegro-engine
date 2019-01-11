#ifndef PREFAB_H
#define PREFAB_H

#include "transform.h"
#include "collider.h"
#include "object.h"
#include "drawable.h"


class Prefab{
	public:
		Prefab(Object* model, Engine* engine);
		Object* instantiate(Transform transform);
		void makeCopy(Object* parent, std::vector<Object*> children);

	protected:
		Object* _model = NULL;
		Engine* _engine = NULL;
};

#endif
