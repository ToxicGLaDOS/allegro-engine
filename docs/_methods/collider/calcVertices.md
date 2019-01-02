---
title: calcVertices
signature: virtual void calcVertices() = 0
---

# WARNING
You do not need to call this function manually. Calling this function is handled by `Engine`. However, for completeness it will be described here.

# Description
Calculates where all the vertices should be for the polygon representation of this `Collider`. This is just a step we have to take before each collision detection cycle and is handled automatically before collision detection by `Engine`.
