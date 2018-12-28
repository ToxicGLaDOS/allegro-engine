---
title: background
signature: unsigned char* background() const
---

# Description
Gets the background color of the camera as an array. This method will always return a pointer to an array of size 3. The order is always red, blue green.


# Example
``` c++
Camera camera = Camera(Vector2(0, 0), Vector2(600, 600), "main camera");

// Sets the background to white
camera.setBackgroundColor(255, 255, 255); 

// Returns an array with values {255, 255, 255}
camera.background();
```
