---
title: collides
signature: bool collides(Collider * other) const
---

# Description
Returns true if this `RectCollider` overlaps with the `other` collider. It should be noted that if two colliders are touching each other, but not overlapping this will return false. Conversely, if one collider is completly contained within the other collider this method will return true.

# Example
``` c++
RectCollider rc1 = RectCollider(Vector2(0, 0) , Vector2(20, 20), "rc1");
RectCollider rc2 = RectCollider(Vector2(10, 0), Vector2(10, 10), "rc2");
RectCollider rc3 = RectCollider(Vector2(20, 0), Vector2(10, 10), "rc3");
rc1.collides(&rc2); // True
rc1.collides(&rc3); // False (even though they share an edge)
```

