#include"image_resource.h"
#include"exceptions.h"
#include<fstream>

ImageResource::ImageResource(const std::string& path){
	// TODO: Check if image addon has been initalized
	// TODO: Add a check for the resources directory
	ALLEGRO_PATH *body = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(body, "resources");
	
	ALLEGRO_PATH *tail = al_create_path(path.c_str());
	al_join_paths(body, tail);
	
	const char* file_path = al_path_cstr(body, '/');
		
	if(std::ifstream(file_path)){

		_bitmap = al_load_bitmap(al_path_cstr(body, '/'));
		if(_bitmap == NULL){
			std::string err = std::string("Image with path: ");
			err.append(file_path);
			err.append(" failed to load");
			throw ResourceLoadException(err);
		}
	}
	else{
		std::string err = std::string("No file exists at path: ");
		err.append(file_path);
		throw ResourceLoadException(err);
	}
	al_destroy_path(body);
	al_destroy_path(tail);
}

ImageResource::~ImageResource(){
}

void ImageResource::destroy(){
	al_destroy_bitmap(_bitmap);
}

ALLEGRO_BITMAP* ImageResource::bitmap() const{
	return _bitmap;
}



