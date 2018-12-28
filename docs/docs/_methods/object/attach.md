---
title: attach
signature: void attach(Object* parent);
---

# Description
Attaches this object to the parent object. The `_parent` field of this object will be set to the parent argument that is pass in. To detach an object just pass `NULL` to this function.

When an object moves it also moves all children objects of it and all children of those objects and so on, always keeping the relative distance the same. Because of this movement propagation, cyclic structures are not allowed. Any attempt to attach an object to another object that is a child, or a child of a child, etc. of this object will raise a `AttachToChildException`, so be sure to detach the child before attaching.

# Example
If `objB` is attached to `objA` and we move `objA` to the left 5 units then `objB` will also be moved to the left 5 units. However, if `objB` is moved to the left 5 units `objA` will not be moved, because it is the parent object.



