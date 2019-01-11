#include"engine.h"
#include"prefab.h"
#include"image_resource.h"
#include"rect_collider.h"
#include"sprite.h"

int main(int argc, char **argv){
	int width = 1000, height = 1000;
	Engine engine = Engine(width, height, 60);
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");


	ImageResource tileImage = ImageResource("tile.png");
	Sprite tileSprite = Sprite(Transform(Vector2(100, 0)), tileImage, "tile");
	RectCollider tileCollider = RectCollider(Vector2(0,0), Vector2(50,50), "tileCollider");

	tileCollider.attach(&tileSprite);

	Prefab tilePrefab = Prefab(&tileSprite, &engine);
	
	for(int x = 0; x < 500; x+=50){
		for(int y = 0; y > -500; y-= 50){
			Object* obj = tilePrefab.instantiate(Transform(Vector2(x, y)));
		}
	}
	

	engine.register_camera(&camera);
	engine.mainLoop();
	return 0;
}
