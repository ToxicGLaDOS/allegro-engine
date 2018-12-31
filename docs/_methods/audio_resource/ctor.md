---
title: ctor
signature: AudioResource(std::string path)
---

# Description
Creates an `AudioResource` that will play the file that `path` points to. This constructor assumes some sensible default values:

`volume` - 100%

`pan` - 0.0

`speed` - 1.0

`loop` - false

Of course you can change any of these using `setVolume`, `setPan` etc.
