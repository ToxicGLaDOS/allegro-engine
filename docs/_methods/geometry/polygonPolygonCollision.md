---
title: polygonPolygonCollision
signature: bool polygonPolygonCollision(const std::vector<Vector2>& poly1, const std::vector<Vector2>&poly2)
---

# Description
Determines whether there is a collision between two polygons using the seperating axis theorem (SAT). `poly1` and `poly2` are lists of points that define the polygon. There are two conditions this function assumes. 

1. The lists of points must be listed in counter-clockwise order.

2. The polygon must be convex.


# Example
Assume you have a polygon that looks like this. 

```
A----B
|    |
|    |
|    |
C----D
```

Then you could list the points `ACDB`, `CDBA`, `DBAC`, or `BACD`, but not any other way.


