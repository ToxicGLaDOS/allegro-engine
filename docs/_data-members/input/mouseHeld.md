---
title: _mouseHeld
definition: std::vector<bool> _mouseHeld
---

# Description
A vector of `bool` values that represents which mouse buttons have been held this frame.

We use a vector instead of an array here because we don't know how many mouse buttons any given mouse will have an we want to handle them all.
