---
title: Collides
signature: virtual bool collides(Collider * other) const = 0
---



# Description
Returns true if this collider overlaps with the other collider. This function is implemented for you by the concrete `Collider` classes (RectCollider, CircleCollider). Usually you will not have to call this function manually, because any `Collider`s you register with the engine will check for collisions against every other collider you registered with the engine each frame. However, it might be useful to create a `Collider` and check for collisions against other colliders only under certian conditions instead of each frame. In this case, you might want to call this function explicitly. Just think carefully about whether you need to call this function explicitly. 
