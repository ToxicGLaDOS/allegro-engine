#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<stdexcept>
#include<string>

class AllegroInitException : public std::runtime_error{
	public:
		AllegroInitException(std::string error);
};

class ResourceLoadException : public std::runtime_error{
	public:
		ResourceLoadException(std::string error);
};

class AllegroCreationException : public std::runtime_error{
	public:
		AllegroCreationException(std::string error);

};

class AudioAttachException : public std::runtime_error{
	public:
		AudioAttachException(std::string error);

};

#endif
