---
title: collides
signature: bool collides(Collider * other) const
---

# Description
Returns true if this `PolygonCollider` overlaps with the `other` collider. It should be noted that if two colliders are touching each other, but not overlapping this will return false. Additionally, if one collider is completly contained within the other collider this method will return `false`.

