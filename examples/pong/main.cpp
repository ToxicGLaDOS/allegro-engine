#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<stdio.h>
#include<string>
#include"object.h"
#include"sprite.h"
#include"square_collider.h"
#include"circle_collider.h"
#include"engine.h"
#include"camera.h"
#include"ball_motion.h"
#include"image_resource.h"


#define COLLIDER_DEBUG

int width = 1000, height = 1000;

enum MYKEYS{
	KEY_UP, KEY_DOWN, KEY_W, KEY_S 
};


void flipdx_collision(Collider * other){
	if(other->name() == "Ball collider"){
		Object* sibling = other->parent()->findChildWithName("Ball motion");
		if(sibling != NULL){
			BallMotion * ball_motion = (BallMotion*)sibling;
			ball_motion->flipDx();
		}
	}
}

void flipdy_collision(Collider * other){
	if(other->name() == "Ball collider"){
		Object* sibling = other->parent()->findChildWithName("Ball motion");
		if(sibling != NULL){
			BallMotion * ball_motion = (BallMotion*)sibling;
			ball_motion->flipDy();
		}
	}
}

void reset_collision(Collider * other){
	if(other->name() == "Ball collider"){
		other->parent()->move_to(Vector2(width/2,-height/2));
	}
}



int main(int argc, char **argv){
	Engine engine = Engine(width, height);	
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");

	bool key[8] = {false, false, false, false};
	if(!al_install_keyboard()){
		printf("Keyboard installation failed\n");
	}
	
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
	
	ImageResource paddle_image = ImageResource("paddle.png");
	ImageResource ball_image = ImageResource("ball.png");

	ALLEGRO_EVENT event;
	bool running = true;
	double ball_speed = 7;

	Vector2 ball_start = Vector2(width/2, -height/2);
	Vector2 ball_size = Vector2(50, 50);
	Vector2 paddle_size = Vector2(50, 250);

	Sprite paddle1 = Sprite(Vector2(0, 0), paddle_image, "Player1 paddle");	
	Sprite paddle2 = Sprite(Vector2(width - 50, 0), paddle_image, "Player2 paddle");
	Sprite ball = Sprite(ball_start, ball_image, "Ball");

	SquareCollider p1_collider = SquareCollider(Vector2(0,0), paddle_size, "P1 collider");
	SquareCollider p2_collider = SquareCollider(Vector2(width - 50, 0), paddle_size, "P2 collider");
	SquareCollider ball_collider = SquareCollider(ball_start, ball_size, "Ball collider");
	SquareCollider left_wall = SquareCollider(Vector2(-10,0), Vector2(10, height), "Left wall collider");
	SquareCollider right_wall = SquareCollider(Vector2(width,0), Vector2(10, height), "Right wall collider");
	SquareCollider top_wall = SquareCollider(Vector2(0, 10), Vector2(width, 10), "Top wall collider");
	SquareCollider bottom_wall = SquareCollider(Vector2(0, -height), Vector2(width, 10), "Bottom wall collider");

	#ifdef COLLIDER_DEBUG
	p1_collider.setDraw(true);
	p2_collider.setDraw(true);
	ball_collider.setDraw(true);
	left_wall.setDraw(true);
	right_wall.setDraw(true);
	top_wall.setDraw(true);
	bottom_wall.setDraw(true);
	#endif

	
	BallMotion ball_motion = BallMotion(ball_speed, ball_speed, "Ball motion");

	p1_collider.attach(&paddle1);
	p2_collider.attach(&paddle2);
	ball_collider.attach(&ball);
	ball_motion.attach(&ball);

	engine.register_camera(&camera);
	
	engine.register_drawable(&paddle1);
	engine.register_drawable(&paddle2);
	engine.register_drawable(&ball);
	
	engine.register_object(&ball_motion);
	
	engine.register_collider(&ball_collider, NULL);
	engine.register_collider(&p1_collider, flipdx_collision);
	engine.register_collider(&p2_collider, flipdx_collision);

	engine.register_collider(&left_wall,   reset_collision);
	engine.register_collider(&right_wall,  reset_collision);
	
	engine.register_collider(&top_wall,    flipdy_collision);
	engine.register_collider(&bottom_wall, flipdy_collision);

	int speed = 5;
	
	ALLEGRO_COLOR background = al_map_rgb(0,0,0);

	while(running){
		al_clear_to_color(background);
		while(!al_is_event_queue_empty(event_queue)){
			if (al_get_next_event(event_queue, &event)){
				if(event.type == ALLEGRO_EVENT_KEY_DOWN){
					if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
						running = false;
					}
					else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
						key[KEY_UP] = true;
					}
					else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
						key[KEY_DOWN] = true;
					}
					else if(event.keyboard.keycode == ALLEGRO_KEY_W){
						key[KEY_W] = true;
					}
					else if(event.keyboard.keycode == ALLEGRO_KEY_S){
						key[KEY_S] = true;
					}
				}
				else if(event.type == ALLEGRO_EVENT_KEY_UP){
					if(event.keyboard.keycode == ALLEGRO_KEY_UP){
						key[KEY_UP] = false;
					}
					else if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
						key[KEY_DOWN] = false;
					}
					else if(event.keyboard.keycode == ALLEGRO_KEY_W){
						key[KEY_W] = false;
					}
					else if(event.keyboard.keycode == ALLEGRO_KEY_S){
						key[KEY_S] = false;
					}
				}	
			}
		}
		if(key[KEY_UP]){
			paddle2.move_by(Vector2(0,speed));
		}
		else if(key[KEY_DOWN]){
			paddle2.move_by(Vector2(0,-speed));
		}
		if(key[KEY_W]){
			paddle1.move_by(Vector2(0, speed));
		}
		else if(key[KEY_S]){
			paddle1.move_by(Vector2(0, -speed));
		}


		engine.update();
		al_flip_display();
	}
	return 0;

}
