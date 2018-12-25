#include"exceptions.h"


AllegroInitException::AllegroInitException(std::string error)
	: std::runtime_error(error){}


ResourceLoadException::ResourceLoadException(std::string error)
	: std::runtime_error(error){}


AllegroCreationException::AllegroCreationException(std::string error)
	: std::runtime_error(error){}


AudioAttachException::AudioAttachException(std::string error)
	: std::runtime_error(error){}
