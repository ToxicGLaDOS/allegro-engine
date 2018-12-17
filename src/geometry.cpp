#include"vector2.h"
#include<math.h>
#include<stdio.h>


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

bool lineCircleIntersection(Vector2 p1, Vector2 p2, Vector2 c_pos, double radius){
	Vector2 v = p2 - p1;
	Vector2 pointToCircle = c_pos - p1;
	Vector2 projection = pointToCircle.projectOnto(v);
	// If the projection is longer than the vector then
	// the project is further than the line segment
	if(pointInCircle(p1 + projection, c_pos, radius) && length(Vector2(0,0), projection) < length(p1, p2)){
		return true;
	}
	else if(pointInCircle(p1, c_pos, radius)){
		return true;		
	}
	else if(pointInCircle(p2, c_pos,radius)){
		return true;
	}

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




