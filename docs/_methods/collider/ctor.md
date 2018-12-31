---
title: ctor
signature: Collider(const Transform& transform, const std::string& name)
---


# Description
Creates a `Collider` with the given transform and name. This class inherits from object, so like all the child classes of `Object` the update method of this class will be called each frame. Because this class has a pure virtual method you should not try to create a `Collider` object.
