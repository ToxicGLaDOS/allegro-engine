---
title: ctor
signature: Collider(const Transform& transform, const std::string& name, bool solid = false, bool fixed = false)
---


# Description
Creates a `Collider` with the given transform and name. This class inherits from object, so like all the child classes of `Object` the update method of this class will be called each frame. 

If `solid` is true the collider will not allow other solid colliders inside it. Instead when another solid collider intersects with this one the colliders will move so they are no longer colliding. This is useful for walls and platforms, characters, etc.

If `fixed` is true the collider will not be allowed to move. So, if two colliders are marked solid and one is marked fixed, only the collider marked not fixed will move when the collision is resloved. In addition, colliders marked fixed will not check for collisions against each other. This is because they can not move and therefore should be known to collide with any other fixed collider upon creation by you. This greatly reduces the amount of collision checking that is required for games that have lots of unmoving tiles that make up the platforms for instance. Collisions are checked normally if one collider is fixed and the other isn't though.

Because this class has a pure virtual method you should not try to create a `Collider` object.
