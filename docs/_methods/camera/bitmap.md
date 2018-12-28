---
title: bitmap
signature: ALLEGRO_BITMAP * bitmap() const
---


# WARNING
This method is not meant to be called manually. This method is required by `Engine`. However, for completeness this method will be described here.

# Description
Returns the `_bitmap` field of this camera so that we can draw it to the screen. This should only be called after everything has been drawn that you want to be drawn.
