---
title: minimumTranslationVector
signature: Collision minimumTranslationVector(const std::vector<Vector2>& poly1, const std::vector<Vector2>&poly2)
---

# Description
Uses the seperating axis theorem algorithm to find 2 things

1. Was there a collision between these two polygons?
2. If there was a collision, how much and in what direction do we need to move the first so they won't collide anymore.

This function is how the engine resolves collisions when colliders are marked solid. For more information on the minimum translation vector check out `mtv` in `Collision`.
