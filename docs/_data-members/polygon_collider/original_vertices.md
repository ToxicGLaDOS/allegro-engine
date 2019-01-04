---
title: _original_vertices
definition: std::vector<Vector2> _original_vertices
---

# Description

The original set of vertices passed into the constructor of this `PolygonCollider`.

We need to keep track of these because any transformation, like rotation or scaling, will compound if we apply them to the already transformed vertices.
