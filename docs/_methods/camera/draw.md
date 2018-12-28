---
title: draw
signature: void draw(Drawable* drawable)
---

# WARNING
This method is not usually one you want to call manually. However, for completeness it will be described here.

# Description
Draws the `Drawable` onto the camera. Calls to `draw` will always overwrite whatever is below the drawable, so calling this method in the proper order is important if you need certain things to appear on top.
