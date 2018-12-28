---
title: Collider
---

Collider is the base class for all colliders in the engine. It is not recommended to inherit from this class yourself, because you must implement collision detection with every other kind of collider. Instead you should inherit from one of the concrete collider classes (SquareCollider, CircleCollider). When you create a collider be sure to register it with the engine by calling `engine.register_collider(&my_collider);`.
