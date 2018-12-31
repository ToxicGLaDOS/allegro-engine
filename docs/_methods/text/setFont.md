---
title: setFont
signature: void setFont(const std::string& fontPath)
---


# Description
Sets the font of the `Text`. `fontPath` should be a relative path starting in the `resources` directory. 

# Examples
For this example assume there are fonts named "times.ttf", and "comic_sans.ttf" in the resources directory.

``` c++
// Makes a text at (0, 0),
// saying "Example!"
// with times.ttf font
// 12 pixels large
// black in color (0, 0, 0)
Text text = Text(Vector2(0, 0), "Example!", "times.ttf", 12, 0, 0, 0);

// Everything remains the same
// except the font is changed to
// comic_sans.ttf
text.setFont("comic_sans.ttf");
```
