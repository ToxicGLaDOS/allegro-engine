---
title: operator==
signature: bool operator==(const Vector2& other) const
---


# Description
Returns whether two `Vector2`s contents are the same. Because of floating point imprecision this will not likely be very useful in its current state. Currently it checks to make sure that both `Vector2`s have exactly the same x and y values. In the future this will probably be changed to be an approximate equality.
