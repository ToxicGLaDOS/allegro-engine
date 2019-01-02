#include"engine.h"
#include"polygon.h"
#include"rect_collider.h"
#include<math.h>

std::vector<Vector2> polygonCircle(double radius, int resolution, double offset){
	std::vector<Vector2> polygon;
	double twopi = 2*M_PI;
	for(int i = 0; i < resolution; i++){
		double t = (i/(double)resolution)*twopi;
		polygon.push_back(Vector2(radius * cos(t) + offset, radius * sin(t) - offset));
	}
	return polygon;
}

std::vector<Vector2> polygonEllipse(double horz, double vert, int resolution, double offset){
	std::vector<Vector2> polygon;
	double twopi = 2*M_PI;
	for(int i = 0; i < resolution; i++){
		double t = (i/(double)resolution)*twopi;
		polygon.push_back(Vector2(horz * cos(t) + offset, vert * sin(t) - offset));
	}
	return polygon;
}

int main(int argc, char **argv){
	int width = 1000, height = 1000;
	Engine engine = Engine(width, height, 60);
	Camera camera = Camera(Vector2(0,0), Vector2(width, height), "main camera");

	std::vector<Vector2> poly1_points;
	std::vector<Vector2> poly2_points;

	double base = 300;
	double size = 150;
	double offset = 200;
	
	poly1_points.push_back(Vector2(base, -base));
	poly1_points.push_back(Vector2(base, -base+size));
	poly1_points.push_back(Vector2(base+size, -base+size));
	poly1_points.push_back(Vector2(base+size, -base));

	
	//poly1_points = polygonCircle(20, 20, 100);
	poly2_points = polygonEllipse(50, 10, 30, 200);	

	Polygon poly1 = Polygon(Transform(Vector2(100, -100)), poly1_points, "poly1");
	Polygon poly2 = Polygon(Transform(Vector2(100+offset, -100-offset)), poly2_points, "poly2");

	poly1.setOther(&poly2);
	poly2.setOther(&poly1);

	camera.setBackgroundColor(60, 0, 0);
	engine.register_drawable(&poly1);
	engine.register_drawable(&poly2);

	engine.register_camera(&camera);

	engine.mainLoop();
	return 0;
}
