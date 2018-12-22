#include"image_resource.h"

ImageResource::ImageResource(std::string path){
	ALLEGRO_PATH *body = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(body, "resources");
	
	ALLEGRO_PATH *tail = al_create_path(path.c_str());
	al_join_paths(body, tail);
	
	_bitmap = al_load_bitmap(al_path_cstr(body, '/'));
}


ALLEGRO_BITMAP* ImageResource::bitmap(){
	return _bitmap;
}



