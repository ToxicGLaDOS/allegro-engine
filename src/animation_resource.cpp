#include "animation_resource.h"
#include "exceptions.h"
#include <experimental/filesystem>
#include <iostream>
#include <fstream>


AnimationResource::AnimationResource(std::string relativePath){
	// Should be just the relative path
	ALLEGRO_PATH *body = al_create_path_for_directory(relativePath.c_str());	
	
	// Full path to the directory so we can check if it exists
	ALLEGRO_PATH *checkPath = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
        al_append_path_component(checkPath, "resources");

        ALLEGRO_PATH *checkTail = al_create_path(relativePath.c_str());
        al_join_paths(checkPath, checkTail);
	
	const char* directoryPath = al_path_cstr(checkPath, '/');
	
	if(std::ifstream(directoryPath)){
		for(auto& file : std::experimental::filesystem::directory_iterator(directoryPath)){
			ALLEGRO_PATH* fullPath = al_create_path(file.path().c_str());
			al_set_path_filename(body, al_get_path_filename(fullPath));
			
			const char* path = al_path_cstr(body, '/');

			_images.push_back(ImageResource(path));
		}
	}
	else{
		std::string error("Animation resource failed to load because directory with path ");
		error.append(directoryPath);
		error.append(" does not exist.");
		throw ResourceLoadException(error);
	}
	// TODO: Sort the paths first
}

AnimationResource::AnimationResource(std::vector<std::string> paths){
	for(std::string path : paths){
		_images.push_back(ImageResource(path));
	}
}


AnimationResource::AnimationResource(std::vector<ImageResource> images)
	: _images(images){}


unsigned int AnimationResource::size() const{
	return _images.size();
}

std::vector<ImageResource> AnimationResource::images() const{
	return _images;
}
