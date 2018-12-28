---
title: isParentOf
signature: bool isParentOf(Object* child)
---

# Description
Checks if this object is the parent of the `child`. Returns true if this object is the parent of `child`, or the parent of the parent of `child`, etc.

# Example
``` c++
Object objA = Object(Vector2(0,0),"objA");
Object objB = Object(Vector2(1,1),"objB");
Object objC = Object(Vector2(2,2),"objC");

objC.attach(&objB);
objB.attach(&objA);

objA.isParentOf(objC); // True
objA.isParentOf(objB); // True
objC.isParentOf(objA); // False
```
