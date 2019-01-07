---
title: ctor
signature: "CircleCollider()\nCircleCollider(const Transform& transform, double radius, const std::string& name, bool solid = false, bool fixed = false)"
---

# Description
Creates a `CircleCollider` at the given transform, radius and name. The position component of `transform` refers to the center of the `CircleCollider`, `radius` refers to the radius of the circle, and `name` refers to the name that you want to give this `CircleCollider`. The `_position` field of `CircleCollider`s refers to their center.

# Example
``` c++
// A CircleCollider at (20, 10) with no rotation or scaling with radius of 15 named "cc1".
// The CircleCollider will be not solid and moveable. (Basically acting as a trigger)
CircleCollider cc1 = CircleCollider(Transform(Vector2(20, 10)), 15, "cc1");
```
