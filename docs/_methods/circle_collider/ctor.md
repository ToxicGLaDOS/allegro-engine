---
title: ctor
signature: "CircleCollider()\nCircleCollider(const Vector2& position, double radius, const std::string& name)"
---

# Description
Creates a `CircleCollider` at the given position with the given radius and name. `position` refers to the top left corner of the `CircleCollider`, `radius` refers to the radius of the circle, and `name` refers to the name that you want to give this `CircleCollider`. It is important to remember that unlike many other objects in your game the `_position` field of `CircleCollider`s refers to their center instead of the top left corner.

# Example
``` c++
// A CircleCollider at (20, 10) with radius of 15 named "cc1".
CircleCollider cc1 = CircleCollider(Vector2(20, 10), 15, "cc1");
```
