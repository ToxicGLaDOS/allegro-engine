---
title: topLeft
signature: virtual Vector2 topLeft() const = 0
---

# Description
Returns the topLeft corner of this drawable. This is important because not everything's position refers to the top left of the object. For instance, circles position refers to its center. We need to know the top left because when drawing we draw from the top left. This function must be implemented if you decided to inherit from this class. However, it is not recommended for you to inherit from this class. Instead, you should inherit from sprite or a collider.


