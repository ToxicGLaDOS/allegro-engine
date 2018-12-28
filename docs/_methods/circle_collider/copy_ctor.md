---
title: copy ctor
signature: CircleCollider(const CircleCollider& other)
---

# Description
This is just a copy constructor that allows you to create a deep copy of a `CircleCollider`. This is important internally, because the `_bitmap` field is a pointer and we need to copy the value over.

# Example
``` c++
CircleCollider cc1 = CircleCollider(Vector2(0, 0), 20, "cc1");

cc1.setDraw(true);

// Without the copy constructor this would cause a double free when rc1 and rc2 fall out of scope
CircleCollider cc2 = cc1;
```
