#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "drawable.h"
#include "animation_resource.h"
#include "transform.h"
#include "engine.h"

class AnimatedSprite : public Drawable{
	public:
		AnimatedSprite(Transform transform, AnimationResource animation, double frameDuration, std::string name, bool loop = false);
		ALLEGRO_BITMAP* getBitmap() const;
		virtual void update();
		void play();
		void stop();
		void setFrame(unsigned int frame);
		void setLoop(bool loop);
		void setFrameDuration(double frameDuration);
	
		AnimationResource animation() const;
		bool loop() const;
		double frameDuration() const;

	protected:
		bool _playing = false;
		bool _loop;
		double _frameDuration;
		AnimationResource _animation;
		unsigned int _curFrame = 0;
	private:
		double _curTime = 0;

};


#endif
