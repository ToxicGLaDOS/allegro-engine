---
title: AttachToChildException
signature: "class AttachToChildException : public std::runtime_error"
---

# Description
Thrown when a parent is attached to a child. Parent objects cannot be attached to thier children because it would create a cyclic structure which would cause an infinite loop when one of the objects moved. If you encounter this error make sure to detach the child first. You can do this by passing `NULL` to the `attach` function.
