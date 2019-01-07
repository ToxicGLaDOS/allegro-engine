---
title: ctor
signature: "RectCollider(const Transform& transform, const Vector2& size, const std::string& name, bool solid = false, bool fixed = false)"
---

# Description
Creates a `RectCollider` with the given transform with the given size and name. The position component of `transform` refers to the top left corner of the `RectCollider`, `size` refers to the dimensions of the rectangle, and `name` refers to the name that you want to give this `RectCollider`. 

# Example
``` c++
// A RectCollider at (20, 10) with width of 40 and height of 50 named "rc1".
// The RectCollider will be a non solid and non fixed
RectCollider rc1 = RectCollider(Transform(Vector2(20, 10)), Vector2(40, 50), "rc1");

// This one is solid and fixed
RectCollider rc2 = RectCollider(Transform(Vector2(0, 0)), Vector2(100, 10), "rc2", true, true);
```
