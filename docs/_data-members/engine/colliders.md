---
title: _colliders
definition: std::vector<Collider*> _colliders
---

# Description
A vector of `Collider` pointers that have been registered with the engine. Each frame every `Collider` in this vector will check for collisions with every other `Collider` that has been registered with the engine. If a collision is detected then the `onCollision` method of both colliders will be called. If the colliders `_draw` field has been set to `true` using `setDraw` then the `Collider` will be drawn each frame as well. 
