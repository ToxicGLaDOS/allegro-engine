#ifndef INPUT_H
#define INPUT_H

#include<string>
#include<allegro5/allegro.h>
#include<map>


class Input{
	public:
		Input();
		void update();
		void clear();
		bool keyPressed(std::string key);
		bool keyReleased(std::string key);
		bool keyHeld(std::string key);
	private:
		
		bool _pressed[ALLEGRO_KEY_MAX] = {false};
		bool _held[ALLEGRO_KEY_MAX] = {false};
		bool _released[ALLEGRO_KEY_MAX] = {false};
		ALLEGRO_EVENT_QUEUE * _event_queue;
		ALLEGRO_EVENT_SOURCE * _keyboard_source; 
	
		// Returns an allegro key code
		int stringToKey(std::string keyName);
		const std::map<std::string, int> _stringKeyMap = {
		{ "a", ALLEGRO_KEY_A },
		{ "b", ALLEGRO_KEY_B },
		{ "c", ALLEGRO_KEY_C },
		{ "d", ALLEGRO_KEY_D },
		{ "e", ALLEGRO_KEY_E },
		{ "f", ALLEGRO_KEY_F },
		{ "g", ALLEGRO_KEY_G },
		{ "h", ALLEGRO_KEY_H },
		{ "i", ALLEGRO_KEY_I },
		{ "j", ALLEGRO_KEY_J },
		{ "k", ALLEGRO_KEY_K },
		{ "l", ALLEGRO_KEY_L },
		{ "m", ALLEGRO_KEY_M },
		{ "n", ALLEGRO_KEY_N },
		{ "o", ALLEGRO_KEY_O },
		{ "p", ALLEGRO_KEY_P },
		{ "q", ALLEGRO_KEY_Q },
		{ "r", ALLEGRO_KEY_R },
		{ "s", ALLEGRO_KEY_S },
		{ "t", ALLEGRO_KEY_T },
		{ "u", ALLEGRO_KEY_U },
		{ "v", ALLEGRO_KEY_V },
		{ "w", ALLEGRO_KEY_W },
		{ "x", ALLEGRO_KEY_X },
		{ "y", ALLEGRO_KEY_Y },
		{ "z", ALLEGRO_KEY_Z },
		{ "0", ALLEGRO_KEY_0 },
		{ "1", ALLEGRO_KEY_1 },
		{ "2", ALLEGRO_KEY_2 },
		{ "3", ALLEGRO_KEY_3 },
		{ "4", ALLEGRO_KEY_4 },
		{ "5", ALLEGRO_KEY_5 },
		{ "6", ALLEGRO_KEY_6 },
		{ "7", ALLEGRO_KEY_7 },
		{ "8", ALLEGRO_KEY_8 },
		{ "9", ALLEGRO_KEY_9 },
		{ "0", ALLEGRO_KEY_PAD_0 },
		{ "1", ALLEGRO_KEY_PAD_1 },
		{ "2", ALLEGRO_KEY_PAD_2 },
		{ "3", ALLEGRO_KEY_PAD_3 },
		{ "4", ALLEGRO_KEY_PAD_4 },
		{ "5", ALLEGRO_KEY_PAD_5 },
		{ "6", ALLEGRO_KEY_PAD_6 },
		{ "7", ALLEGRO_KEY_PAD_7 },
		{ "8", ALLEGRO_KEY_PAD_8 },
		{ "9", ALLEGRO_KEY_PAD_9 },
		{ "1", ALLEGRO_KEY_F1 },
		{ "2", ALLEGRO_KEY_F2 },
		{ "3", ALLEGRO_KEY_F3 },
		{ "4", ALLEGRO_KEY_F4 },
		{ "5", ALLEGRO_KEY_F5 },
		{ "6", ALLEGRO_KEY_F6 },
		{ "7", ALLEGRO_KEY_F7 },
		{ "8", ALLEGRO_KEY_F8 },
		{ "9", ALLEGRO_KEY_F9 },
		{ "10", ALLEGRO_KEY_F10 },
		{ "11", ALLEGRO_KEY_F11 },
		{ "12", ALLEGRO_KEY_F12 },
		{ "escape", ALLEGRO_KEY_ESCAPE },
		{ "tilde", ALLEGRO_KEY_TILDE },
		{ "minus", ALLEGRO_KEY_MINUS },
		{ "equals", ALLEGRO_KEY_EQUALS },
		{ "backspace", ALLEGRO_KEY_BACKSPACE },
		{ "tab", ALLEGRO_KEY_TAB },
		{ "openbrace", ALLEGRO_KEY_OPENBRACE },
		{ "closebrace", ALLEGRO_KEY_CLOSEBRACE },
		{ "enter", ALLEGRO_KEY_ENTER },
		{ "semicolon", ALLEGRO_KEY_SEMICOLON },
		{ "quote", ALLEGRO_KEY_QUOTE },
		{ "backslash", ALLEGRO_KEY_BACKSLASH },
		{ "backslash2", ALLEGRO_KEY_BACKSLASH2 },
		{ "comma", ALLEGRO_KEY_COMMA },
		{ "fullstop", ALLEGRO_KEY_FULLSTOP },
		{ "slash", ALLEGRO_KEY_SLASH },
		{ "space", ALLEGRO_KEY_SPACE },
		{ "insert", ALLEGRO_KEY_INSERT },
		{ "delete", ALLEGRO_KEY_DELETE },
		{ "home", ALLEGRO_KEY_HOME },
		{ "end", ALLEGRO_KEY_END },
		{ "pgup", ALLEGRO_KEY_PGUP },
		{ "pgdn", ALLEGRO_KEY_PGDN },
		{ "left", ALLEGRO_KEY_LEFT },
		{ "right", ALLEGRO_KEY_RIGHT },
		{ "up", ALLEGRO_KEY_UP },
		{ "down", ALLEGRO_KEY_DOWN },
		{ "pad_slash", ALLEGRO_KEY_PAD_SLASH },
		{ "pad_asterisk", ALLEGRO_KEY_PAD_ASTERISK },
		{ "pad_minus", ALLEGRO_KEY_PAD_MINUS },
		{ "pad_plus", ALLEGRO_KEY_PAD_PLUS },
		{ "pad_delete", ALLEGRO_KEY_PAD_DELETE },
		{ "pad_enter", ALLEGRO_KEY_PAD_ENTER },
		{ "printscreen", ALLEGRO_KEY_PRINTSCREEN },
		{ "pause", ALLEGRO_KEY_PAUSE },
		{ "abnt_c1", ALLEGRO_KEY_ABNT_C1 },
		{ "yen", ALLEGRO_KEY_YEN },
		{ "kana", ALLEGRO_KEY_KANA },
		{ "convert", ALLEGRO_KEY_CONVERT },
		{ "noconvert", ALLEGRO_KEY_NOCONVERT },
		{ "at", ALLEGRO_KEY_AT },
		{ "circumflex", ALLEGRO_KEY_CIRCUMFLEX },
		{ "colon2", ALLEGRO_KEY_COLON2 },
		{ "kanji", ALLEGRO_KEY_KANJI },
		{ "lshift", ALLEGRO_KEY_LSHIFT },
		{ "rshift", ALLEGRO_KEY_RSHIFT },
		{ "lctrl", ALLEGRO_KEY_LCTRL },
		{ "rctrl", ALLEGRO_KEY_RCTRL },
		{ "alt", ALLEGRO_KEY_ALT },
		{ "altgr", ALLEGRO_KEY_ALTGR },
		{ "lwin", ALLEGRO_KEY_LWIN },
		{ "rwin", ALLEGRO_KEY_RWIN },
		{ "menu", ALLEGRO_KEY_MENU },
		{ "scrolllock", ALLEGRO_KEY_SCROLLLOCK },
		{ "numlock", ALLEGRO_KEY_NUMLOCK },
		{ "capslock", ALLEGRO_KEY_CAPSLOCK },
		{ "pad_equals", ALLEGRO_KEY_PAD_EQUALS },
		{ "backquote", ALLEGRO_KEY_BACKQUOTE },
		{ "semicolon2", ALLEGRO_KEY_SEMICOLON2 },
		{ "command", ALLEGRO_KEY_COMMAND }
		};

};


#endif
