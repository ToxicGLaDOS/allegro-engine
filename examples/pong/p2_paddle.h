#ifndef P2_PADDLE_H
#define P2_PADDLE_H

#include"sprite.h"
#include"image_resource.h"

class P2Paddle : public Sprite{
	public:
		P2Paddle(const Vector2& pos, float speed, const ImageResource& image, const std::string& name);
		void update();
	private:
		float _speed;


};


#endif
