---
title: rectRectIntersection
signature: bool rectRectIntersection(const Vector2& r1_pos, const Vector2& r1_size, const Vector2& r2_pos, const Vector2& r2_size)
---

# Description
Returns true if the rectangle defined by `r1_pos` and `r1_size` collides with the rectangle defined by `r2_pos` and `r2_size`

# Example
``` c++
// True
rectRectIntersection(Vector2(0, 0), Vector2(10, 10), Vector2(5, 5), Vector2(10, 10));

// False
rectRectIntersection(Vector2(0, 0), Vector2(10, 10), Vector2(15, 15), Vector2(5, 5));

// True (even though r2 is contained in r1)
rectRectIntersection(Vector2(0, 0), Vector2(10, 10), Vector2(1, 1), Vector2(9, 9));



```
