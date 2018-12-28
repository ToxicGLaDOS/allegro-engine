---
title: setBackgroundColor
signature: void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b)
---


# Description
Sets the color of the background for this camera. Whenever there is space that is not taken up by drawables this is the color that will appear there. The color is in RGB color space and expects a number between 0-255. Because this function takes an `unsigned char` passing a number out of this range will cause the number to be cast to an `unsigned char` and will likely not have the value you were expecting.

# Example
``` c++
Camera camera = Camera(Vector2(0, 0), Vector2(600, 600), "main camera");

// Sets the background to white
camera.setBackgroundColor(255, 255, 255); 
```
