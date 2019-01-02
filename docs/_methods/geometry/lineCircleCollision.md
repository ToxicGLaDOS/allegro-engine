---
title: lineCircleCollision
signature: bool lineCircleCollision(const Vector2& p1, const Vector2& p2, const Vector2& c_pos, double radius)
---

# Description
Returns true if the line defined by `p1` and `p2` collides with the circle defined by `c_pos` and `radius`. If the line is completely contained within the circle this function still returns true.

# Example
``` c++

// True
lineCircleCollision(Vector2(0, 0), Vector2(10, 10), Vector2(5, 5), 5);

// False
lineCircleCollision(Vector2(0, 0), Vector2(10, 10), Vector2(10, 0), 3);

// True (even though the line is completely contained in the circle)
lineCircleCollision(Vector2(5, 5), Vector2(10, 10), Vector2(4, 4), 10);

```
