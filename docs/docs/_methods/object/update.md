---
title: update
signature: virtual void update()
---

# Description
This function is meant to be overridden by your objects that derive from `Object` (or from children of `Object`). This function will be called on every one of your `Objects` that you register with the engine each frame. Because this is called each frame, your should take care to not put any infinite loops, or any extremely expensive operations in the update method as it will freeze things up. 

You may notice that this method is not pure virtual. That is because you don't always need something to happen every update for some objects and it would be inconvenient to have to implement this method every time just to have it blank. To solve this problem the method is simply virtual with no body. If you do not override this method it will do nothing.


``` c++
// Every update we check for if 'w' or 's' is held down and if they are we move the object accordingly.
void UpAndDownMover::update(){
                Input input = *_engine->input();
                if(input.keyHeld("w")){
                        moveBy(Vector2(0, 5));
                }
                else if(input.keyHeld("s")){
                        moveBy(Vector2(0, -5));
                }

}
```
