#ifndef ANIMATION_RESOURCE_H
#define ANIMATION_RESOURCE_H

#include <string>
#include <vector>
#include "image_resource.h"

class AnimationResource{
	public:
		// Should be a directory and takes everything in that directory
		AnimationResource(std::string path);
		// A list of paths to files. Will be in the order they appear in the list
		AnimationResource(std::vector<std::string> paths);
		// A list of images. Will be in the order they appear in this list.
		AnimationResource(std::vector<ImageResource> images);
		unsigned int size() const;
		std::vector<ImageResource> images() const;
	protected:
		std::vector<ImageResource> _images;
};


#endif
