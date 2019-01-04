#include"engine.h"
#include"circle_spawner.h"
#include"circle_collider.h"

int main(int argc, char **argv){
	int width = 1000, height = 1000;
	Engine engine = Engine(width, height, 60);
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");
	
	CircleSpawner cs = CircleSpawner(Transform(Vector2(0,0)), "Circle spawner");
	
	engine.register_object(&cs);
	engine.register_camera(&camera);
	engine.mainLoop();
	return 0;
}
