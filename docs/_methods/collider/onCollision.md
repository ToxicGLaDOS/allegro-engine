---
title: onCollision
signature: virtual void onCollision(Collider* other)
---

# Description
This function will be called each frame that this `Collider` overlaps with any other collider that has been registered with the engine (assuming you've registered this collider with the engine as well). When you inherit from this class or from the concrete collider classes (RectCollider, CircleCollider) you should override this method.
You may notice this method is virtual and not pure virtual. That is because there are times when you don't want to have anything happen on a collision and it would be tedious to have to implement this function every time that happens. So instead it is defined as virtual with an empty body. Meaning that if you don't override this method then it will be called, but nothing will happen.
