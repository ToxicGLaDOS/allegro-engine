#include"input.h"


Input::Input(){
	if(!al_install_keyboard()){
		// TODO: Raise error
		printf("Keyboard installation failed\n");
	}
	
	_event_queue = al_create_event_queue();
	_keyboard_source = al_get_keyboard_event_source();
	al_register_event_source(_event_queue, _keyboard_source);
	
}

Input::~Input(){
}

void Input::update(){
	ALLEGRO_EVENT event;
	while(!al_is_event_queue_empty(_event_queue)){
		if (al_get_next_event(_event_queue, &event)){
			if(event.type == ALLEGRO_EVENT_KEY_DOWN){
				_pressed[event.keyboard.keycode] = true;
				_held[event.keyboard.keycode] = true;
			}
			else if(event.type == ALLEGRO_EVENT_KEY_UP){
				_released[event.keyboard.keycode] = true;
				_held[event.keyboard.keycode] = false;
			}
		}
	}
}

void Input::destroy(){
	al_unregister_event_source(_event_queue, _keyboard_source);
	al_destroy_event_queue(_event_queue);
}

void Input::clear(){
	// TODO: Maybe keep track of which ones need to be changed in update
	// then we only need to change the ones that need changing back
	// or perhaps keep a seperate array that is always false to make it just a pointer swap
	for(int i = 0; i < ALLEGRO_KEY_MAX; i++){
		_pressed[i] = false;
		_released[i] = false;
	}
}

bool Input::keyPressed(const std::string& key) const{
	return _pressed[stringToKey(key)];
}

bool Input::keyReleased(const std::string& key) const{
	return _released[stringToKey(key)];
}

bool Input::keyHeld(const std::string& key) const{
	return _held[stringToKey(key)];
}

int Input::stringToKey(const std::string& keyName) const{
	//TODO: Error check for bad keyNames
	return _stringKeyMap.at(keyName);		
}




