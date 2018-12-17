#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<stdio.h>
#include"object.h"
#include"sprite.h"
#include"square_collider.h"
#include"geometry.h"


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
	

	Vector2 p_g1= Vector2(120, 12);
	Vector2 p_g2 = Vector2(450, 550);

	Vector2 p_b1 = Vector2(120, 453);
	Vector2 p_b2 = Vector2(500, 453);
	
	Vector2 p_r1 = Vector2(400, 0);
	Vector2 p_r2 = Vector2(400, 200);

	Vector2 p_p1 = Vector2(0, 400);
	Vector2 p_p2 = Vector2(250, 400);

	Vector2 r_pos = Vector2(400,400);
	Vector2 r_size = Vector2(50,50);
	
	Vector2 c_pos = Vector2(400, 400);
	double radius = 50;
	
	Vector2 v = p_g2 - p_g1;
	Vector2 pointToCircle = c_pos - p_g1;
	Vector2 projection = pointToCircle.projectOnto(v);


	
	printf("p_g1 = (%f, %f)\n", p_g1.x(), p_g1.y());
	printf("p_g2 = (%f, %f)\n", p_g2.x(), p_g2.y());
	printf("p_g1.dot(p_g2) = %f\n", p_g1.dot(p_g2));
	printf("p_g2.dot(p_g1) = %f\n", p_g2.dot(p_g1));
	printf("||p_g1|| = %f\n", length(Vector2(0,0), p_g1));
	printf("||p_g2|| = %f\n", length(Vector2(0,0), p_g2));
	printf("p_g1.projectOnto(p_g2) = (%f,%f)\n", p_g1.projectOnto(p_g2).x(), p_g1.projectOnto(p_g2).y());
	printf("v = (%f, %f)\n", v.x(), v.y());
	printf("pointToCircle = (%f, %f)\n", pointToCircle.x(), pointToCircle.y());
	printf("black projection vector = (%f, %f)\n", projection.x(), projection.y());
	printf("green line collides with circle = ");
	printf(lineCircleIntersection(p_g1, p_g2, c_pos, radius) ? "true\n" : "false\n");
	printf("blue line collides with circle = ");
	printf(lineCircleIntersection(p_b1, p_b2, c_pos, radius) ? "true\n" : "false\n");
	printf("red line collides with circle = ");
	printf(lineCircleIntersection(p_r1, p_r2, c_pos, radius) ? "true\n" : "false\n");
	printf("purple line collides with circle = ");
	printf(lineCircleIntersection(p_p1, p_p2, c_pos, radius) ? "true\n" : "false\n");

	
	printf("rect collides with circle = ");
	printf(rectCircleIntersection(r_pos, r_size, c_pos, radius) ? "true\n" : "false\n");


	while(running){
		al_clear_to_color(al_map_rgb(100,0,0));	
		
		if (al_get_next_event(event_queue, &event)){
			if(event.type == ALLEGRO_EVENT_KEY_DOWN){
				if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
					running = false;
				}
				else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
				}
			} 
		}
		al_draw_line(p_g1.x(), p_g1.y(), p_g2.x(), p_g2.y(), al_map_rgb(0, 200, 0), 3);
		al_draw_line(p_b1.x(), p_b1.y(), p_b2.x(), p_b2.y(), al_map_rgb(0, 0, 200), 3);
		al_draw_line(p_r1.x(), p_r1.y(), p_r2.x(), p_r2.y(), al_map_rgb(255, 0, 0), 3);
		al_draw_line(p_p1.x(), p_p1.y(), p_p2.x(), p_p2.y(), al_map_rgb(200, 0, 200), 3);
		al_draw_line(p_g1.x(), p_g1.y(), p_g1.x() + projection.x(), p_g1.y() + projection.y(), al_map_rgb(0,0,0), 1);
		al_draw_circle(c_pos.x(), c_pos.y(), radius, al_map_rgb(0, 200, 0), 1);	
		al_draw_rectangle(r_pos.x(), r_pos.y(), r_pos.x() + r_size.x(), r_pos.y() + r_size.y(), al_map_rgb(0,200,0), 1);
		
		al_flip_display();
	}
	al_destroy_display(display);
	return 0;

}
