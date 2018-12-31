---
title: ctor
signature: "Object(const Transform& transform, const std::string& name);"
---


# Description
Creates an `Object` with the given transform and with the given name.


# Example
``` c++
// creates an object at (0, 0) with no rotation or scaling named "objA";
Object objA = Object(Transform(Vector2(0, 0)), "objA"); 
```


