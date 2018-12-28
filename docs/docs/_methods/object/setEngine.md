---
title: setEngine
signature: void setEngine(Engine*)
---

# Description
Sets the engine pointer in this object. This should not be called manually. It is used by the register_xxx functions of engine so that your objects can have a pointer to the engine. Having this pointer is particularly useful for reading inputs within a method of the object.

