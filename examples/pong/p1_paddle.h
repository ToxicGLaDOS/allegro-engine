#ifndef P1_PADDLE_H
#define P1_PADDLE_H

#include"sprite.h"
#include"image_resource.h"

class P1Paddle : public Sprite{
	public:
		P1Paddle(const Transform& trans, float speed, const ImageResource& image, const std::string& name);
		void update();
	private:
		float _speed;


};

#endif
