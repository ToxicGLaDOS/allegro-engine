#include"text.h"
#include"exceptions.h"
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<stdio.h>
#include<iostream>

Text::Text(const Transform& transform, const std::string& text, const std::string& fontPath, int size, unsigned char r, unsigned char g, unsigned char b, const std::string& name)
	: Drawable(transform, name)
	, _text(text)
	, _size(size)
	, _color(al_map_rgb(r,g,b)){
	
	ALLEGRO_PATH *body = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(body, "resources");
	
	ALLEGRO_PATH *tail = al_create_path(fontPath.c_str());
	al_join_paths(body, tail);
	_font = al_load_font(al_path_cstr(body,'/'), _size, 0);
	if(_font == NULL){
		throw ResourceLoadException("Font failed to load!");
	}
	al_destroy_path(body);
	al_destroy_path(tail);

	makeBitmap();	
}


ALLEGRO_BITMAP* Text::getBitmap() const{
	return _bitmap;
}

void Text::setText(const std::string& text){
	_text = text;
	makeBitmap();
}

void Text::setColor(unsigned char r, unsigned char g, unsigned char b){
	_color = al_map_rgb(r,g,b);
	makeBitmap();
}

void Text::setFont(const std::string& fontPath){
	ALLEGRO_PATH *body = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(body, "resources");
	
	ALLEGRO_PATH *tail = al_create_path(fontPath.c_str());
	al_join_paths(body, tail);
	_font = al_load_font(al_path_cstr(body,'/'), _size, 0);
	if(_font == NULL){
		throw ResourceLoadException("Font failed to load!");
	}
	al_destroy_path(body);
	al_destroy_path(tail);

	makeBitmap();	
}

void Text::setSize(int size){
	_size = size;
	makeBitmap();
}

unsigned char* Text::color() const{
	unsigned char r, g, b;
	al_unmap_rgb(_color, &r, &g, &b);
	static unsigned char array[3] = {r, g, b};
	return array;
}

int Text::size() const{
	return _size;
}

std::string Text::text() const{
	return _text;
}

void Text::makeBitmap(){
	int width = al_get_text_width(_font, _text.c_str());
	int height = al_get_font_line_height(_font);

	_bitmap = al_create_bitmap(width, height);
	al_set_target_bitmap(_bitmap);
	al_draw_text(_font, _color, 0, 0, ALLEGRO_ALIGN_LEFT, _text.c_str());
}

