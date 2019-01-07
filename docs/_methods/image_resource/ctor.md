---
title: ctor
signature: ImageResource(const std::string& path)
---

# Description
Creates an `ImageResource` with the image that `path` points to. Make sure that `path` is relative to the `resources` directory.
Passing a `path` that does not lead to any file will cause a `ResourceLoadException` to be thrown.
