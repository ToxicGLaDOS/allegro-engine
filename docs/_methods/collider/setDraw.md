---
title: setDraw
signature: void setDraw(bool draw)
---

# Description
Sets the draw field of this `Collider`.
Sometimes it is useful to see where a collider is for debugging purposes. To accomplish this, each collider has a draw field that determines whether the collider should be drawn. Collider drawing is for debugging purposes only, so there is no color or line thickness control. 

# Example
``` c++
RectCollider rc = RectCollider(Vector2(0, 0), Vector2(10, 10), "rc");
rc.setDraw(true); // The collider will now be drawn as if it were any other Drawable
```
