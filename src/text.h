#ifndef TEXT_H
#define TEXT_H


#include"drawable.h"
#include<allegro5/allegro5.h>
#include<allegro5/allegro_font.h>

class Text : public Drawable{
	public:
		Text(const Vector2& pos, const std::string& text, const std::string& fontPath, int size, 
				unsigned char r, unsigned char g, unsigned char b, const std::string& name);
		ALLEGRO_BITMAP* getBitmap() const;
		Vector2 topLeft() const;

		void setText(const std::string& text);
		void setColor(unsigned char r, unsigned char g, unsigned char b);
		void setFont(const std::string& fontPath);
		void setSize(int size);

		unsigned char* color() const;
		int size() const;
		std::string text() const;


	private:
		ALLEGRO_BITMAP* _bitmap;
		ALLEGRO_FONT* _font;
		ALLEGRO_COLOR _color = al_map_rgb(255, 255, 255);
		int _size;
		std::string _text;

		void makeBitmap();

};




#endif
