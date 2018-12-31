---
title: ctor
signature: Camera(const Transform& transform, const Vector2& size, const std::string& name)
---

# Description
Creates a camera object with the given transform, size and name. The position component of the transform of the camera is always the top left corner of the cameras vision. Size determines how large the field of vision is on the camera. If the aspect ratio of the camera (size.y()/size.x()) is not the same as the aspect ratio of the window then things can look squashed, so if this is not the desired behaviour take care to make their aspect ratio the same. Name refers to the name of the `Camera` object.


# Example
``` c++
Engine engine = Engine(400, 400, 60);

// Creates a camera at (0, 0) with size (400, 400) named "main camera"
Camera camera = Camera(Transform(Vector2(0, 0)), Vector2(400, 400), "main camera");

// Registers the camera with the engine
engine.register_camera(&camera);
```
