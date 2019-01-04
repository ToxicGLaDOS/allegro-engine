---
title: cameraToWorldSpace
signature: Vector2 cameraToWorldSpace(const Vector2& point)
---

# Description
Converts a point from camera space to world space.

The cameras coordinate system is different from the world space coordinate system. The top left corner of the camera is the origin (0, 0) in camera space and positive y is down from there instead of up. Because of these differing coordinate systems it can be hard to know where in world space your cursor is when the `mousePosition` method of `Input` only gives the camera space position of the mouse. To solve this problem we have `cameraToWorldSpace`.

