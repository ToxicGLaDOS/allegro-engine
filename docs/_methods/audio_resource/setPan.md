---
title: setPan
signature: void setPan(float pan)
---

# Description
Sets the pan of this `AudioResource`. Pan is which speaker is playing louder in stereo sound. `pan` should be a value between -1.0-1.0. If `pan` is not in this range it will be clamped into this range. A pan of -1.0 means only playing through left speaker, a pan of 1.0 means only playing through right speaker, and a pan of 0.0 is balanced.
