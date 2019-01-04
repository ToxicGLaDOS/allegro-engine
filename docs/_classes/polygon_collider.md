---
title: PolygonCollider
---

`PolygonCollider` is the most versitile collider as it can make up any polygon you can imagine, but comes with some limitations and difficulties.

## Limitations

When creating a polygon collider be sure to calculate your points correctly. Read the documentation for the constructor for more specifics.

Make sure the polygon you are defining is convex! If the polygon is not convex, collision detection will register collisions incorrectly. If you must use some kind of concave shape, break it up into multiple convex polygons instead.
