---
title: register_collider
signature: void register_collider(Collider * coll)
---

# Description
Registers a `Collider` with the engine. Every `Collider` will check for collisions against every other `Collider` that has been registered each frame. If a collision is detected then the `onCollision` method of both colliders will be called each frame that they remain overlapped. If the collider has been set to draw using the `setDraw` method then it will be drawn every frame.
