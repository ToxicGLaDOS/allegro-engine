#include<stdio.h>
#include<string>
#include"engine.h"
#include"sprite.h"
#include"text.h"
#include"ball_motion.h"
#include"image_resource.h"
#include"audio_resource.h"
#include"horz_wall_collider.h"
#include"vert_wall_collider.h"
#include"paddle_collider.h"
#include"p1_paddle.h"
#include"p2_paddle.h"


#define COLLIDER_DEBUG

int width = 1000, height = 1000;


int main(int argc, char **argv){
	Engine engine = Engine(width, height, 120);	
	Camera camera = Camera(Vector2(0, 0), Vector2(width, height), "main camera");
	
	ImageResource paddle_image = ImageResource("paddle.png");
	ImageResource ball_image = ImageResource("ball.png");
	
	AudioResource bounce_sound = AudioResource("ball_hit.wav");
	AudioResource goal_sound = AudioResource("goal.wav");

	Text p1_score = Text(Transform(Vector2(width/4,0))  , "0", "nakula.ttf", 100, 255, 255, 255, "P1 score text");
	Text p2_score = Text(Transform(Vector2(width*3/4,0)), "0", "nakula.ttf", 100, 255, 255, 255, "P2 score text");

	bool running = true;
	double ball_speed = 7;

	Transform ball_start = Transform(Vector2(width/2, -height/2));
	Vector2 ball_size = Vector2(50, 50);
	Vector2 paddle_size = Vector2(50, 250);

	Transform p1_start = Transform(Vector2(50, -125));
	Transform p2_start = Transform(Vector2(width - 50, -125));

	Transform l_wall_trans = Transform(Vector2(-5, -height/2));
	Transform r_wall_trans = Transform(Vector2(width + 5, -height/2));
	Transform t_wall_trans = Transform(Vector2(width/2, 5));
	Transform b_wall_trans = Transform(Vector2(width/2, -height-5));
	
	P1Paddle paddle1 = P1Paddle(p1_start, 5, paddle_image, "Player1 paddle");
	P2Paddle paddle2 = P2Paddle(p2_start, 5, paddle_image, "Player2 paddle");
	Sprite ball = Sprite(ball_start, ball_image, "Ball");


	PaddleCollider p1_collider = PaddleCollider(p1_start, paddle_size, "P1 collider", &bounce_sound);
	PaddleCollider p2_collider = PaddleCollider(p2_start, paddle_size, "P2 collider", &bounce_sound);
	RectCollider ball_collider = RectCollider(ball_start, ball_size, "Ball collider");

	VertWallCollider left_wall = VertWallCollider(l_wall_trans, Vector2(10, height), "Left wall collider", &goal_sound, &p2_score);
	VertWallCollider right_wall = VertWallCollider(r_wall_trans, Vector2(10, height), "Right wall collider", &goal_sound, &p1_score);
	HorzWallCollider top_wall = HorzWallCollider(t_wall_trans, Vector2(width, 10), "Top wall collider");
	HorzWallCollider bottom_wall = HorzWallCollider(b_wall_trans, Vector2(width, 10), "Bottom wall collider");

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

	camera.attachGUI(&p1_score);
	camera.attachGUI(&p2_score);

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

	camera.setBackgroundColor(50,50,50);
	
	engine.mainLoop();


	paddle_image.destroy();
	ball_image.destroy();

	return 0;

}
