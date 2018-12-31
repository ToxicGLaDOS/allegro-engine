---
title: distance
signature: double distance(const Vector2& v1, const Vector2& v2)
---

# Description
Returns the distance between the two given points. 


``` c++
// 4
distance(Vector2(0, 0), Vector2(0, 4));

// 4
distance(Vector2(0, 0), Vector2(4, 0));

// sqrt(32) ~ 5.66
distance(Vector2(0, 0), Vector2(4, 4));
```
