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

void Input::clear(){
	// TODO: Maybe keep track of which ones need to be changed in update
	// then we only need to change the ones that need changing back
	// or perhaps keep a seperate array that is always false to make it just a pointer swap
	for(int i = 0; i < ALLEGRO_KEY_MAX; i++){
		_pressed[i] = false;
		_released[i] = false;
	}
}

bool Input::keyPressed(std::string key){
	return _pressed[stringToKey(key)];
}

bool Input::keyReleased(std::string key){
	return _released[stringToKey(key)];
}

bool Input::keyHeld(std::string key){
	return _held[stringToKey(key)];
}

int Input::stringToKey(std::string keyName){
	//TODO: Error check for bad keyNames
	return _stringKeyMap.at(keyName);		
}




