---
title: ctor
signature: Collider(const Vector2& pos, const std::string& name)
---


# Description
Creates a `Collider` at the given position with the given name. This class inherits from object, so like all the child classes of `Object` the update method of this class will be called each frame. Because this class has a pure virtual method you should not try to create a `Collider` object.
