#include"image_resource.h"
#include"exceptions.h"

ImageResource::ImageResource(const std::string& path){
	ALLEGRO_PATH *body = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(body, "resources");
	
	ALLEGRO_PATH *tail = al_create_path(path.c_str());
	al_join_paths(body, tail);
		
	_bitmap = al_load_bitmap(al_path_cstr(body, '/'));
	if(_bitmap == NULL){
		std::string err = std::string("Image with path: ");
		err.append(al_path_cstr(body, '/'));
		err.append(" failed to load");
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



