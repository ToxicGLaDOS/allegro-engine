#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<stdio.h>
#include"object.h"
#include"sprite.h"


int main(int argc, char **argv){
	al_init();
	al_init_image_addon();
	if(!al_install_keyboard()){
		printf("Keyboard installation failed\n");
	}
	ALLEGRO_DISPLAY * display = al_create_display(640,560);
	
	ALLEGRO_BITMAP * image = al_load_bitmap("cat.png");
	ALLEGRO_BITMAP * image2 = al_load_bitmap("cat2.png");
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

	
	Sprite * sprite = new Sprite(0,0,"sprite1",image);
	Sprite * sprite2 = new Sprite(100,100,"sprite2",image2);
	sprite2->attach(sprite);
	
	std::vector<Object*> children = sprite->get_children();
	

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
		al_flip_display();
	}
	al_destroy_display(display);
	return 0;

}
