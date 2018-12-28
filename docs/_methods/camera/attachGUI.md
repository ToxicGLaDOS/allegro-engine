---
title: attachGUI
signature: void attachGUI(Drawable* drawable)
---

# Description
Attaches a `Drawable` to this camera. The position of the `Drawable` will be interpretted in camera space. Meaning, no matter where the camera's position is (0, 0) always refers to the top left of the camera. There is nothing special about the `Drawable` passed in to this function (except the way it's position is handled), so if you register it with the engine it's update method will be called every frame as usual. Note that it usually makes more sense to register it as an object rather than a `Drawable`, because if you register it as a `Drawable` it will be drawn to the scene.
 
