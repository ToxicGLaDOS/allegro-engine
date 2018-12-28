---
title: children
signature: std::vector<Object*> children() const
---

# Description
Returns the direct children of this object. This method makes no guarentees about the order of the children in the vector that it returns.

# Example
``` c++
Object objA = Object(Vector2(0,0), "objA");
Object objB = Object(Vector2(0,0), "objB");
Object objC = Object(Vector2(0,0), "objC");
Object objD = Object(Vector2(0,0), "objD");

objB.attach(&objA);
objC.attach(&objA);
objD.attach(&objA);

objA.children(); // Returns a std::vector with pointers to objB, objC, and objD in no particular order
```
