#include "animated_sprite.h"


AnimatedSprite::AnimatedSprite(Transform transform, AnimationResource animation, double duration, std::string name, bool loop/*= false*/)
	: Drawable(transform, name)
	, _frameDuration(duration)
	, _loop(loop)
	, _animation(animation){}


ALLEGRO_BITMAP* AnimatedSprite::getBitmap() const{
	return _animation.images()[_curFrame].bitmap();
}

void AnimatedSprite::update(){
	if(_playing){
		double time = _engine->deltaTime();
		_curTime += time;
		if(_curTime >= _frameDuration){
			_curTime -= _frameDuration;
			_curFrame = (_curFrame + 1) % _animation.size();
		}
	}
}

void AnimatedSprite::play(){
	_playing = true;
}

void AnimatedSprite::stop(){
	_playing = false;
}

void AnimatedSprite::setFrame(unsigned int frame){
	_curFrame = frame;
}

void AnimatedSprite::setFrameDuration(double duration){
	_frameDuration = duration;
}

void AnimatedSprite::setLoop(bool loop){
	_loop = loop;
}

bool AnimatedSprite::loop() const{
	return _loop;
}

double AnimatedSprite::frameDuration() const{
	return _frameDuration;
}

AnimationResource AnimatedSprite::animation() const{
	return _animation;
}
