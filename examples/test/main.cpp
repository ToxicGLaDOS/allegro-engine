#include"engine.h"

int main(int argc, char **argv){
	int width = 1000, height = 1000;
	Engine engine = Engine(width, height, 60);
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");
	
	engine.register_camera(&camera);
	engine.mainLoop();
	return 0;
}
