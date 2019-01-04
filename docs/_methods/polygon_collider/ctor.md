---
title: ctor
signature: "PolygonCollider(const Transform& transform, std::vector<Vector2> points, const std::string& name)"
---

# Description
Creates a `PolygonCollider` with the given transform with the given points and name. The position component of `transform` refers to the center of the `PolygonCollider`, `points` refers to the vertices of the polygon, and `name` refers to the name that you want to give this `PolygonCollider`.

When creating a `PolygonCollider` the argument for `points` should be centered around the origin. If you do not center the vertices around the origin then any rotation or scaling will cause the object to move around in unintended ways. Use the position component of `transform` to place the `PolygonCollider` where you want it instead of passing points that center around where you want it. 

