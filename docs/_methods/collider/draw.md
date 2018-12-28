---
title: draw
signature: void draw() const
---

# Description
Returns the `_draw` field of this `Collider`. By default this value is set to false, but can be set using the `setDraw` method.


# Example
``` c++
RectCollider rc = RectCollider(Vector2(0, 0), Vector2(10, 10), "rc");
rc.draw(); // False
rc.setDraw(true);
rc.draw(); // True
```
