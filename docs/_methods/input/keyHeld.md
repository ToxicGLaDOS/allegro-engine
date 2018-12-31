---
title: keyHeld
signature: bool keyHeld(const std::string& key) const
---

# Description
Returns true if the key passed in is down, otherwise returns false. This is different than `keyPressed` because it will return true every frame until it is released.
