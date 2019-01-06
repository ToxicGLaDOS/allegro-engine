#ifndef GRAVITY_H
#define GRAVITY_H

#include"object.h"

class Gravity : public Object{
	public:
		Gravity(const Transform& trans, const std::string& name);
		void update();
	protected:
		double speed = 3;
};

#endif
