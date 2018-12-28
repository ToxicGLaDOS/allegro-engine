---
title: Engine
---

Engine is the class that handles most of the frame to frame operations of your game. Checking collisions, drawing everything in the scene, etc. All objects that you want to be handled by the engine need to be registered with the engine first. To do so use the correct `register_xxx` method to suit your needs. Engine also handles the creation and destruction of the display window. When creating a display keep in mind the aspect ratio of the display so you can create a camera with the same aspect ratio. Failure to do so will create squashed looking images.
