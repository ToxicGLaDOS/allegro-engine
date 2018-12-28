---
title: Camera
---

# Description
Camera is the class that draws all of the objects in your game. An engine object requires a camera, and trying to call `engine.mainLoop` without a camera will result in unexpected behaviour. When you create an `Engine` object be sure to register the camera using the `register_camera` method of `Engine`.
