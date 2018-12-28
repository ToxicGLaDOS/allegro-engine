---
title: collides
signature: bool collides(Collider * other) const
---

# Description
Returns true if this `CircleCollider` overlaps with the `other` collider. It should be noted that if two colliders are touching each other, but not overlapping this will return false. Conversely, if one collider is completly contained within the other collider this method will return true.

# Example
``` c++
CircleCollider cc1 = CircleCollider(Vector2(0, 0) , 5, "cc1");
CircleCollider cc2 = CiccleCollider(Vector2(10, 0), 20, "cc2");
CircleCollider cc3 = CiccleCollider(Vector2(10, 0), 5, "cc3");
cc1.collides(&cc2); // True
cc1.collides(&cc3); // False (even though they touch)
```

