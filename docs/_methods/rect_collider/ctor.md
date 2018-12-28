---
title: ctor
signature: "RectCollider()\nRectCollider(const Vector2& position, const Vector2& size, const std::string& name)"
---

# Description
Creates a `RectCollider` at the given position with the given size and name. `position` refers to the top left corner of the `RectCollider`, `size` refers to the dimensions of the rectangle, and `name` refers to the name that you want to give this `RectCollider`. If no arguments are given to the constructor then both position and size will be assumed to be (0, 0) and the name will be an empty string.

# Example
``` c++
// A RectCollider at (20, 10) with width of 40 and height of 50 named "rc1".
RectCollider rc1 = RectCollider(Vector2(20, 10), Vector2(40, 50), "rc1");

RectCollider rc2;

// Same as rc2
RectCollider rc3 = RectCollider(Vector2(0, 0), Vector2(0, 0), "");
```
