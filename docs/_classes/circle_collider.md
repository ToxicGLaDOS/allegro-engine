---
title: CircleCollider
---


CircleCollider is a collider in the shape of a circle. It is one of the main ways you can detect collisions between objects in your game. When you create a Collider of any kind be sure to register it with the engine using `engine.register_collider(&my_collider)`. Once a collider is registered with the engine it will automatically detect collisions between every other collider that has been registered with the engine. When a collision is detected the `onCollision` method of both colliders will be called.
