---
title: copy ctor
signature: RectCollider(const RectCollider& other)
---

# Description
This is just a copy constructor that allows you to create a deep copy of a `RectCollider`. This is important internally, because the `_bitmap` field is a pointer and we need to copy the value over.

# Example
``` c++
RectCollider rc1 = RectCollider(Vector2(0, 0), Vector2(30, 40), "rc1");

rc.setDraw(true);

// Without the copy constructor this would cause a double free when rc1 and rc2 fall out of scope
RectCollider rc2 = rc1;
```
