#ifndef BALL_MOTION_H
#define BALL_MOTION_H

#include"object.h"
#include<string>

class BallMotion : public Object{
	public:
		BallMotion(double dx, double dy, std::string name);
		void update();
		void flipDx();
		void flipDy();
	private:
		double _dx,_dy;
	
};



#endif
