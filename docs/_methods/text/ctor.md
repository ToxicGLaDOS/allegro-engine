---
title: ctor
signature: "Text(const Transform& transform, const std::string& text, const std::string& fontPath, int size,
                                unsigned char r, unsigned char g, unsigned char b, const std::string& name);"
---


# Description
Creates a text object with the following properties.

`transform` - The position, rotation and scale of the text

`text` - The content of the text

`fontPath` - The relative path starting from `resources` to the font. If this path does not lead to a file a `ResourceLoadException` will be thrown

`size` - The size in pixels of the text

`r` - The intensity of the red component of the text

`g` - The intensity of the green component of the text

`b` - The intensity of the blue component of the text

