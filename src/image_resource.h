#ifndef IMAGE_RESOURCE_H
#define IMAGE_RESOURCE_H

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<string>

class ImageResource{
	public:
		ImageResource(const std::string& path);
		ALLEGRO_BITMAP* bitmap() const;
	private:
		ALLEGRO_BITMAP* _bitmap;

};


#endif
