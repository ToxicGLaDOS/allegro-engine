---
title: pointInCircle
signature: bool pointInCircle(const Vector2& point, const Vector2& c_pos, double radius)
---

# Description
Returns true if the `point` is in the circle defined by `c_pos` and `radius`.


# Example
``` c++
// True
pointInCircle(Vector2(5, 5), Vector2(4, 4), 5);

// False
pointInCircle(Vector2(2, 2), Vector2(10, 0), 5);
```
