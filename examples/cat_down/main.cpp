#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<stdio.h>
#include"object.h"
#include"sprite.h"
#include"square_collider.h"

int main(int argc, char **argv){
	al_init();
	al_init_image_addon();
	al_init_primitives_addon();

	if(!al_install_keyboard()){
		printf("Keyboard installation failed\n");
	}
	ALLEGRO_DISPLAY * display = al_create_display(640,560);
	
	ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "resources");

	al_set_path_filename(path, "cat.png");
	ALLEGRO_BITMAP * image = al_load_bitmap(al_path_cstr(path, '/'));

	al_set_path_filename(path, "cat2.png");
	ALLEGRO_BITMAP * image2 = al_load_bitmap(al_path_cstr(path, '/'));


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

	SquareCollider coll = SquareCollider(Vector2(100,100),Vector2(400,400), "collider1");
	SquareCollider coll2 = SquareCollider(Vector2(450,50), Vector2(150,150), "collider2");
	Sprite * sprite = new Sprite(0,0,"sprite1",image);
	Sprite * sprite2 = new Sprite(100,100,"sprite2",image2);
	sprite2->attach(sprite);
	coll.attach(sprite);
	coll2.attach(sprite);
	printf(coll.collides(&coll2) ? "true\n" : "false\n");
	std::vector<Object*> children = sprite->get_children();
	ALLEGRO_COLOR green = al_map_rgb(0, 200, 0);	

	while(running){
		al_clear_to_color(al_map_rgb(100,0,0));	
		
		if (al_get_next_event(event_queue, &event)){
			if(event.type == ALLEGRO_EVENT_KEY_DOWN){
				if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					running = false;
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
					sprite->move_by(Vector2(0,5));
				}
			} 
		}
		sprite->draw();	
		sprite2->draw();
		coll.draw(green, 1);
		coll2.draw(green, 1);
		al_flip_display();
	}
	al_destroy_display(display);
	return 0;

}
