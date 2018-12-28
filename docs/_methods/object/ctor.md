---
title: ctor
signature: "Object(int x_pos, int y_pos, const std::string& name);\nObject(const Vector2& pos, const std::string& name);"
---


# Description
Creates an `Object` with the given position, either at `x_pos`, `y_pos` or at the coordinates given by the `Vector2` `pos` and with the given name.


# Example
``` c++
Object objA = Object(Vector2(0, 0), "objA") // creates an object at 0, 0 named "objA";
Object objB = Object(0, 0, "objB") // creates an object at 0, 0 named "objB";
```


