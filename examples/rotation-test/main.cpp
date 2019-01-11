#include"engine.h"
#include"rect_collider.h"
#include"prefab.h"
#include"mover.h"

int main(int argc, char **argv){
	int width = 1000, height = 1000;
	Engine engine = Engine(width, height, 60);
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");
	
	Mover rc1 = Mover(Transform(Vector2(0, 0)), Vector2(100, 100), "rc1");
	RectCollider rc2 = RectCollider(Transform(Vector2(100, -150)), Vector2(50, 20), "rc2");
	RectCollider rc3 = RectCollider(Transform(Vector2(100, -200)), Vector2(20, 75), "rc3");


	rc3.attach(&rc2);
	rc2.attach(&rc1);

	rc1.setDraw(true);
	rc2.setDraw(true);
	rc3.setDraw(true);

	engine.register_collider(&rc1);
	engine.register_collider(&rc2);
	engine.register_collider(&rc3);
	//Prefab colliderPrefab = Prefab(&rc1, &engine);
	//colliderPrefab.instantiate(Transform(Vector2(400, -400)));

	engine.register_camera(&camera);
	engine.mainLoop();
	return 0;
}
