#include"engine.h"

int main(int argc, char **argv){
	int width = 1000, height = 1000;
	Engine engine = Engine(width, height);	
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");
	
	engine.register_camera(&camera);
	bool running = true;	
	while(running){
		Input input = *engine.input();
		
		engine.update();
		if(input.keyHeld("escape")){
			engine.destroyDisplay();
			running = false;
		}	
	}
	return 0;
}
