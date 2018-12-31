---
title: rectCircleIntersection
signature: bool rectCircleIntersection(const Vector2& r_pos, const Vector2& r_size, const Vector2& c_pos, double radius)
---

# Description
Returns true if the rectangle defined by `r_pos` and `r_size` collides with the circle defined by `c_pos` and `radius`.

# Example
``` c++
// True
rectCircleIntersection(Vector2(0, 0), Vector2(10, 10), Vector2(10, 10), 5);

// False
rectCircleIntersection(Vector2(0, 0), Vector2(5, 5), Vector2(8, 8), 2);

// True (even though the circle is completely contained in the rectangle)
rectCircleIntersection(Vector2(0, 0), Vector2(10, 10), Vector2(5, 5), 3);

// True (even though the rectangle is completely contained in the circle)
rectCircleIntersection(Vector2(5, 5), Vector2(10, 10), Vector2(7.5, 7.5), 10);

```
