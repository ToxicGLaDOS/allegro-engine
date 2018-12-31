---
title: circleCircleIntersection
signature: bool circleCircleIntersection(const Vector2& c1_pos, double r1, const Vector2& c2_pos, double r2)
---


# Description
Returns true if the circle defined by `c1_pos` and `r1` collides with the circle defined by `c2_pos1 and `r2`

# Example
``` c++

// True
circleCircleIntersection(Vector2(5, 5), 5, Vector2(5, 8), 4);

// False
circleCircleIntersection(Vector2(1, 1), 1, Vector2(8, 8), 2);

// True (even though one circle contains the other
circleCircleIntersection(Vector2(10, 10), 10, Vector2(10, 10), 5);


```
