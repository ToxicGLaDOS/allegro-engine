#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<stdio.h>
#include<string>
#include"object.h"
#include"sprite.h"
#include"square_collider.h"
#include"circle_collider.h"
#include"geometry.h"
#include"engine.h"
#include"camera.h"


void onCollision(Collider* other){
	printf((other->name() + "\n").c_str());
}

int main(int argc, char **argv){
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();

	if(!al_install_keyboard()){
		printf("Keyboard installation failed\n");
	}
	
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "resources");

	ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
	ALLEGRO_EVENT_SOURCE * keyboard_source = al_get_keyboard_event_source();
	al_register_event_source(event_queue, keyboard_source);
	
	if(event_queue == NULL){
		printf("Queue creation error\n");
		return -1;
	}
	if(keyboard_source == NULL){
		printf("Keyboard subsystem not installed?\n");
		return -1;
	}

	ALLEGRO_EVENT event;
	bool running = true;
	

	Camera camera = Camera(Vector2(-100, 300), Vector2(500, 500), "main camera");
	Engine engine = Engine(500, 500);	
	engine.register_camera(&camera);
	

	Vector2 r_pos = Vector2(0, 0);
	Vector2 r_size = Vector2(50,50);
	SquareCollider square = SquareCollider(r_pos, r_size, "square collider");
	SquareCollider square2 = SquareCollider(Vector2(175, -50), Vector2(50, 50), "square collider2");	
	SquareCollider rect = SquareCollider(Vector2(50, 50), Vector2(300, 10), "rect collider");
	engine.register_collider(&square, onCollision);
	engine.register_collider(&square2, onCollision);
	engine.register_collider(&rect, onCollision);
	square.setDraw(true);
	square2.setDraw(true);
	rect.setDraw(true);

	Vector2 c_pos = Vector2(100, -100);
	double radius = 50;
	CircleCollider circle = CircleCollider(c_pos, radius, "circle collider");
	engine.register_collider(&circle, onCollision);
	circle.setDraw(true);
	int speed = 5;

	while(running){
		al_clear_to_color(al_map_rgb(100,0,0));	
		
		if (al_get_next_event(event_queue, &event)){
			if(event.type == ALLEGRO_EVENT_KEY_DOWN){
				if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					running = false;
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
					square.move_by(Vector2(0, -speed));
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
					square.move_by(Vector2(0, speed));
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_LEFT){
					square.move_by(Vector2(-speed, 0));
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_RIGHT){
					square.move_by(Vector2(speed, 0));
				}
			} 
		}
		engine.update();
		al_flip_display();
	}
	return 0;

}
