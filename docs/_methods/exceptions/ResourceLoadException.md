---
title: ResourceLoadException
signature: "class AllegroInitException : public std::runtime_error" 
---

# Description
Thrown when a resource fails to load. This is usually because the file path passed to the resource was incorrect. Make sure that the path you pass in is the relative path starting from `resources`. `resources` should be adjacent to your `main.cpp` file. For example if you had a file in `resources` called `my_sound.wav` then you should pass the string "my_sound.wav" in as the path parameter to the resource.
