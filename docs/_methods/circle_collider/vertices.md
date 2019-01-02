---
title: vertices
signature: std::vector<Vector2> vertices() const
---

# Description
Returns a vector of points that correspond to the vertices of this `CircleCollider`. Because collision is slow with circles and we would need a different collision detection function for every pair of shapes we approximate the circle as a polygon with vertices on the circle. This should not change collision detection very much and makes the code much more simple and efficient.
