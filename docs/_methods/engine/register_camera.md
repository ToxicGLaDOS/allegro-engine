---
title: register_camera
signature: void register_camera(Camera * camera)
---

# Description
Registers a camera with the engine. When a camera is registered it becomes the camera that handles drawing for the engine. For example, if cameraA is registered then cameraB becomes registered the view will be from cameraB's perspective and to get cameraA's view again you would need to call `register_camera` on cameraA again. A camera should be registered before you call `mainLoop`. Failure to do so will result in an exception being thrown.


