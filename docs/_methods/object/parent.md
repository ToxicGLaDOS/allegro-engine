---
title: parent
signature: Object* parent() const
---

# Description
Returns the parent of this object. You can set a parent by using the `attach` method.

# Example
``` c++
Object objA = Object(Vector2(0,0), "objA");
Object objB = Object(Vector2(0,0), "objB");

objB.attach(&objA); // objA is now the parent of objB
objB.parent(); // Returns a pointer to objA
```

