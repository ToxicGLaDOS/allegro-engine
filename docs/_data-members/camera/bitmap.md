---
title: _bitmap
definition: ALLEGRO_BITMAP * _bitmap
---

# WARNING
You should not mess with this variable directly. Functions like `draw`, `drawGUI`, and more rely on this varible. To draw things to the camera register drawables with the `Engine` or attach GUIs to the camera using `attachGUI`

# Description
The bitmap of what this camera sees. This is the variable that is updated every time we draw to the camera.
