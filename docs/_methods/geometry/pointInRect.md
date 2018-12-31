---
title: pointInRect
signature: bool pointInRect(const Vector2& point, const Vector2& rect_pos, const Vector2& rect_size)
---

# Description
Returns true if `point` is inside the rectangle defined by `rect_pos` and `rect_size`.


# Example
``` c++
// True
pointInRect(Vector2(10, 10), Vector2(5, 5), Vector2(10, 10));

// False
pointInRect(Vector2(0, 0), Vector2(5, 5), Vector2(10, 10));
```
