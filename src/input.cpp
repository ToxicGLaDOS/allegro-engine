#include"input.h"
#include"exceptions.h"
#include<stdexcept>

Input::Input(){
	if(!al_install_keyboard()){
		throw AllegroInitException("Keyboard failed to install!");
	}
	if(!al_install_mouse()){
		throw AllegroInitException("Mouse failed to install!");
	}
	_numAxes = al_get_mouse_num_axes();
	_numButtons = al_get_mouse_num_buttons();

	for(int i = 0; i < _numButtons; i++){
		_mousePressed.push_back(false);
		_mouseReleased.push_back(false);
		_mouseHeld.push_back(false);
	}
	
	_event_queue = al_create_event_queue();
	_keyboard_source = al_get_keyboard_event_source();
	_mouse_source = al_get_mouse_event_source();
	al_register_event_source(_event_queue, _keyboard_source);
	al_register_event_source(_event_queue, _mouse_source);	
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
			else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
				// subtract 1 because mouse buttons are 1 indexed for some reason
				_mousePressed[event.mouse.button - 1] = true;
				_mouseHeld[event.mouse.button - 1] = true;
			}
			else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
				_mouseReleased[event.mouse.button - 1] = true;
				_mouseHeld[event.mouse.button - 1] = false;

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

	for(int i = 0; i < _mousePressed.size(); i++){
		_mousePressed[i] = false;
		_mouseHeld[i] = false;
		_mouseReleased[i] = false;
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

bool Input::mouseButtonPressed(int buttonNum) const{
	return _mousePressed[buttonNum];
}

bool Input::mouseButtonReleased(int buttonNum) const{
	return _mouseReleased[buttonNum];
}

bool Input::mouseButtonHeld(int buttonNum) const{
	return _mouseHeld[buttonNum];
}

Vector2 Input::mousePosition() const{
	ALLEGRO_MOUSE_STATE mouseState;
	al_get_mouse_state(&mouseState);
	return Vector2(mouseState.x, mouseState.y);
}

int Input::stringToKey(const std::string& keyName) const{
	// TODO: Check if this can be made more efficent by saving the iterator
	// when it does find it and then use that instead of at?
	if(_stringKeyMap.find(keyName) == _stringKeyMap.end()){
		std::string error = "Key name \"";
		error.append(keyName);
		error.append("\" not found");
		throw std::invalid_argument(error);
	}
	return _stringKeyMap.at(keyName);		
}




