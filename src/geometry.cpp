#include"vector2.h"
#include<math.h>
#include<stdio.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>

bool pointInRect(Vector2 point, Vector2 rect_pos, Vector2 rect_size){
	if(rect_pos.x() < point.x() 
	&& rect_pos.x() + rect_size.x() > point.x() 
	&& rect_pos.y() < point.y() 
	&& rect_pos.y() + rect_size.y() > point.y()){
		return true;	
	}
	else{
		return false;
	}
}

double length(Vector2 v1, Vector2 v2){
	return std::sqrt(pow(v2.x() - v1.x(), 2) + pow(v2.y() - v1.y(), 2));
}

bool pointInCircle(Vector2 point, Vector2 c_pos, double radius){
	if(length(point, c_pos) < radius){
		return true;
	}
	else{
		return false;
	}
}


int sign(double a){
	if(a > 0)
		return 1;
	else if(a < 0)
		return -1;
	else
		return 0;
}

bool lineCircleIntersection(Vector2 p1, Vector2 p2, Vector2 c_pos, double radius){
	Vector2 v = p2 - p1;
	Vector2 pointToCircle = c_pos - p1;
	Vector2 projection = pointToCircle.projectOnto(v);

	// The sign of the projection vector must match the sign of the vector v
	// this is because if it doesn't it means the vector is going in the opposite direction (off of the line segment)	
	if(sign(v.x()) == sign(projection.x()) && sign(v.y()) == sign(projection.y())){	
		// If the projection is longer than the vector then
		// the project is further than the line segment
		if(pointInCircle(p1 + projection, c_pos, radius) && length(Vector2(0,0), projection) < length(p1, p2)){
			#ifdef DEBUG
			// Draw line
			al_draw_line(p1.x(), p1.y(), p2.x(), p2.y(), al_map_rgb(200,0,0), 3);
			
			// Draw point to circle
			al_draw_line(p1.x(), p1.y(), (p1+pointToCircle).x(), (p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

			// Draw projection
			al_draw_line(p1.x(), p1.y(), (p1+projection).x(), (p1+projection).y(), al_map_rgb(0, 0, 0), 1);	
			#endif
			return true;
		}
	}
	if(pointInCircle(p1, c_pos, radius)){
		#ifdef DEBUG
		// Draw line
		al_draw_line(p1.x(), p1.y(), p2.x(), p2.y(), al_map_rgb(0,0,200), 3);
		
		// Draw point to circle
		al_draw_line(p1.x(), p1.y(), (p1+pointToCircle).x(), (p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

		// Draw projection
		al_draw_line(p1.x(), p1.y(), (p1+projection).x(), (p1+projection).y(), al_map_rgb(0, 0, 0), 1);
		#endif
		return true;		
	}
	else if(pointInCircle(p2, c_pos,radius)){
		#ifdef DEBUG
		// Draw line
		al_draw_line(p1.x(), p1.y(), p2.x(), p2.y(), al_map_rgb(0,0,200), 3);
		
		// Draw point to circle
		al_draw_line(p1.x(), p1.y(), (p1+pointToCircle).x(), (p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

		// Draw projection
		al_draw_line(p1.x(), p1.y(), (p1+projection).x(), (p1+projection).y(), al_map_rgb(0, 0, 0), 1);
		#endif
		return true;
	}
	#ifdef DEBUG
	// Draw line
	al_draw_line(p1.x(), p1.y(), p2.x(), p2.y(), al_map_rgb(0,200,0), 3);
	
	// Draw point to circle
	al_draw_line(p1.x(), p1.y(), (p1+pointToCircle).x(), (p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

	// Draw projection
	al_draw_line(p1.x(), p1.y(), (p1+projection).x(), (p1+projection).y(), al_map_rgb(0, 0, 0), 1);
	#endif


	return false;
}

bool rectCircleIntersection(Vector2 r_pos, Vector2 r_size, Vector2 c_pos, double radius){
	
	Vector2 a = r_pos;
	Vector2 b = Vector2(r_pos.x(),              r_pos.y() + r_size.y());
	Vector2 c = Vector2(r_pos.x() + r_size.x(), r_pos.y() + r_size.y());
	Vector2 d = Vector2(r_pos.x() + r_size.x(), r_pos.y());


	if(pointInRect(c_pos, r_pos, r_size)){
		printf("Center of circle in rect\n");
		return true;
	}
	else if(   lineCircleIntersection(a, b, c_pos, radius)
		|| lineCircleIntersection(b, c, c_pos, radius)
		|| lineCircleIntersection(c, d, c_pos, radius)
		|| lineCircleIntersection(d, a, c_pos, radius)){
		return true;
	}

	return false;
}




