---
title: mtv
definition: Vector2 mtv
---

# Description
The Minimum Translation Vector (MTV) for the collision. This `Vector2` gives the minimum distance and direction needed for one collider to move so that it will be no longer colliding with the other collider anymore. This vector is always relative to the first polygon in the argument list of the `minimumTranslationVector` method. Meaning if you want to know how much to move the second polygon you need to negate this vector.
