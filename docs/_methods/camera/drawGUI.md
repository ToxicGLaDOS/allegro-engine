---
title: drawGUI
signature: void drawGUI()
---

# WARNING
You do not need to call this method manually. Calls to this method are handled by `Engine`. However, for completeness it will be described here.

# Description
Draws everything attached to this camera with `attachGUI` to this camera's bitmap. We need this to be seperate from the normal `draw` method because GUIs are always drawn on top of everything else and they appear on the screen statically instead of moving when the camera moves. 


