---
title: register_object
signature: void register_object(Object * object)
---

# Description
Registers an object with the engine. All registered objects will have their `update` methods called once each frame. Sometimes it may be benificial to register a `Drawable` with this function instead of the `register_drawable` method. This is usually the case for objects attached to the camera using `attachGUI`, because you may want the `update` method to be called each frame, but not want to draw the `Drawable` as a normal object. Because `Drawable` inherits from `Object` this is possible with this method.
