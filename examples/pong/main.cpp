#include<stdio.h>
#include<string>
#include"engine.h"
#include"sprite.h"
#include"ball_motion.h"
#include"image_resource.h"
#include"audio_resource.h"
#include"horz_wall_collider.h"
#include"vert_wall_collider.h"
#include"paddle_collider.h"



#define COLLIDER_DEBUG

int width = 1000, height = 1000;


int main(int argc, char **argv){
	Engine engine = Engine(width, height);	
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");
	
	ImageResource paddle_image = ImageResource("paddle.png");
	ImageResource ball_image = ImageResource("ball.png");
	
	AudioResource bounce_sound = AudioResource("ball_hit.wav");
	AudioResource goal_sound = AudioResource("goal.wav");

	bool running = true;
	double ball_speed = 7;

	Vector2 ball_start = Vector2(width/2, -height/2);
	Vector2 ball_size = Vector2(50, 50);
	Vector2 paddle_size = Vector2(50, 250);

	Sprite paddle1 = Sprite(Vector2(0, 0), paddle_image, "Player1 paddle");	
	Sprite paddle2 = Sprite(Vector2(width - 50, 0), paddle_image, "Player2 paddle");
	Sprite ball = Sprite(ball_start, ball_image, "Ball");


	PaddleCollider p1_collider = PaddleCollider(Vector2(0,0), paddle_size, "P1 collider", &bounce_sound);
	PaddleCollider p2_collider = PaddleCollider(Vector2(width - 50, 0), paddle_size, "P2 collider", &bounce_sound);
	SquareCollider ball_collider = SquareCollider(ball_start, ball_size, "Ball collider");
	VertWallCollider left_wall = VertWallCollider(Vector2(-10,0), Vector2(10, height), "Left wall collider", &goal_sound);
	VertWallCollider right_wall = VertWallCollider(Vector2(width,0), Vector2(10, height), "Right wall collider", &goal_sound);
	HorzWallCollider top_wall = HorzWallCollider(Vector2(0, 10), Vector2(width, 10), "Top wall collider");
	HorzWallCollider bottom_wall = HorzWallCollider(Vector2(0, -height), Vector2(width, 10), "Bottom wall collider");

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
	
	engine.register_collider(&ball_collider);
	engine.register_collider(&p1_collider);
	engine.register_collider(&p2_collider);

	engine.register_collider(&left_wall);
	engine.register_collider(&right_wall);
	
	engine.register_collider(&top_wall);
	engine.register_collider(&bottom_wall);

	int speed = 5;
	camera.setBackgroundColor(50,50,50);
	while(running){
		Input input = *engine.input();
		
		if(input.keyHeld("up")){
			paddle2.move_by(Vector2(0,speed));
		}
		else if(input.keyHeld("down")){
			paddle2.move_by(Vector2(0,-speed));
		}
		if(input.keyHeld("w")){
			paddle1.move_by(Vector2(0, speed));
		}
		else if(input.keyHeld("s")){
			paddle1.move_by(Vector2(0, -speed));
		}


		engine.update();
		if(input.keyHeld("escape")){
			engine.destroyDisplay();
			paddle_image.destroy();
			ball_image.destroy();
			running = false;
		
		}
	
	}
	return 0;

}
