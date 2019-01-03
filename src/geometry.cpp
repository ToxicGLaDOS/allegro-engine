#include"vector2.h"
#include<math.h>
#include<stdio.h>
#include<vector>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>

bool pointInRect(const Vector2& point, const Vector2& rect_pos, const Vector2& rect_size){
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

double distance(const Vector2& v1, const Vector2& v2){
	return std::sqrt(pow(v2.x() - v1.x(), 2) + pow(v2.y() - v1.y(), 2));
}

bool pointInCircle(const Vector2& point, const Vector2& c_pos, double radius){
	if(distance(point, c_pos) < radius){
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


bool lineCircleCollision(const Vector2& p1, const Vector2& p2, const Vector2& c_pos, double radius){
	Vector2 v = p2 - p1;
	Vector2 pointToCircle = c_pos - p1;
	Vector2 projection = pointToCircle.projectOnto(v);
	
	// The sign of the projection vector must match the sign of the vector v
	// this is because if it doesn't it means the vector is going in the opposite direction (off of the line segment)	
	if(sign(v.x()) == sign(projection.x()) && sign(v.y()) == sign(projection.y())){	
		// If the projection is longer than the vector then
		// the project is further than the line segment
		if(pointInCircle(p1 + projection, c_pos, radius) && distance(Vector2(0,0), projection) < distance(p1, p2)){
			#ifdef DEBUG
			// Draw line
			al_draw_line(p1.x(), -p1.y(), p2.x(), -p2.y(), al_map_rgb(200,0,0), 3);
			
			// Draw point to circle
			al_draw_line(p1.x(), -p1.y(), (p1+pointToCircle).x(), -(p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

			// Draw projection
			al_draw_line(p1.x(), -p1.y(), (p1+projection).x(), -(p1+projection).y(), al_map_rgb(0, 0, 0), 1);	
			#endif
			return true;
		}
	}
	if(pointInCircle(p1, c_pos, radius)){
		#ifdef DEBUG
		// Draw line
		al_draw_line(p1.x(), -p1.y(), p2.x(), -p2.y(), al_map_rgb(0,0,200), 3);
		
		// Draw point to circle
		al_draw_line(p1.x(), -p1.y(), (p1+pointToCircle).x(), -(p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

		// Draw projection
		al_draw_line(p1.x(), -p1.y(), (p1+projection).x(), -(p1+projection).y(), al_map_rgb(0, 0, 0), 1);
		#endif
		return true;		
	}
	else if(pointInCircle(p2, c_pos,radius)){
		#ifdef DEBUG
		// Draw line
		al_draw_line(p1.x(), -p1.y(), p2.x(), -p2.y(), al_map_rgb(0,0,200), 3);
		
		// Draw point to circle
		al_draw_line(p1.x(), -p1.y(), (p1+pointToCircle).x(), -(p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

		// Draw projection
		al_draw_line(p1.x(), -p1.y(), (p1+projection).x(), -(p1+projection).y(), al_map_rgb(0, 0, 0), 1);
		#endif
		return true;
	}
	#ifdef DEBUG
	// Draw line
	al_draw_line(p1.x(), -p1.y(), p2.x(), -p2.y(), al_map_rgb(0,200,0), 3);
	
	// Draw point to circle
	al_draw_line(p1.x(), -p1.y(), (p1+pointToCircle).x(), -(p1+pointToCircle).y(), al_map_rgb(200, 0, 200), 1);

	// Draw projection
	al_draw_line(p1.x(), -p1.y(), (p1+projection).x(), -(p1+projection).y(), al_map_rgb(0, 0, 0), 1);
	#endif


	return false;
}

bool rectCircleCollision(const Vector2& r_pos, const Vector2& r_size, const Vector2& c_pos, double radius){
	
	Vector2 a = Vector2(r_pos.x(),              r_pos.y());
	Vector2 b = Vector2(r_pos.x(),              r_pos.y() - r_size.y());
	Vector2 c = Vector2(r_pos.x() + r_size.x(), r_pos.y() - r_size.y());
	Vector2 d = Vector2(r_pos.x() + r_size.x(), r_pos.y());


	if(pointInRect(c_pos, r_pos, r_size)){
		return true;
	}
	else if(   lineCircleCollision(a, b, c_pos, radius)
		|| lineCircleCollision(b, c, c_pos, radius)
		|| lineCircleCollision(c, d, c_pos, radius)
		|| lineCircleCollision(d, a, c_pos, radius)){
		return true;
	}

	return false;
}

bool rectRectCollision(const Vector2& r1_pos, const Vector2& r1_size, const Vector2& r2_pos, const Vector2& r2_size){
	Vector2 left_pos, right_pos, top_pos, bottom_pos, left_size, top_size;


	if(r1_pos.x() < r2_pos.x()){
		left_pos = r1_pos;
		left_size = r1_size;
		right_pos = r2_pos;
	}
	else{
		left_pos = r2_pos;
		left_size = r2_size;
		right_pos = r1_pos;
	}
	if(r1_pos.y() > r2_pos.y()){
		top_pos = r1_pos;
		top_size = r1_size;
		bottom_pos = r2_pos;
	}
	else{
		top_pos = r2_pos;
		top_size = r2_size;
		bottom_pos = r1_pos;
	}

	if(left_pos.x() + left_size.x() > right_pos.x() && top_pos.y() - top_size.y() < bottom_pos.y()){
		return true;
	}
	else{
		return false;
	}
} 

bool circleCircleCollision(const Vector2& c1_pos, double r1, const Vector2& c2_pos, double r2){
	if(distance(c1_pos, c2_pos) < r1 + r2){
		return true;
	}
	else{
		return false;
	}

} 


Vector2 getCenter(const std::vector<Vector2>& poly){
	double minx = poly[0].x(), maxx = poly[0].x(), miny = poly[0].y(), maxy = poly[0].y();
	for(Vector2 v : poly){
		if(v.x() < minx)
			minx = v.x();
		if(v.x() > maxx)
			maxx = v.x();
		if(v.y() < miny)
			miny = v.y();
		if(v.y() > maxy)
			maxy = v.y();
	}
	return Vector2((maxx + minx)/2, (maxy + miny)/2);
}

bool polygonPolygonCollision(const std::vector<Vector2>& poly1, const std::vector<Vector2>& poly2){
	std::vector<Vector2> normals;
	
	for(int i = 0; i < poly1.size(); i++){
		Vector2 p1 = poly1[i];
		Vector2 p2 = poly1[(i + 1) % poly1.size()];
		
		Vector2 direction = p2 - p1;
		normals.push_back(Vector2(direction.y(), -direction.x()).normalized());
	}

	for(int i = 0; i < poly2.size(); i++){
		Vector2 p1 = poly2[i];
		Vector2 p2 = poly2[(i + 1) % poly2.size()];
		
		Vector2 direction = p2 - p1;
		normals.push_back(Vector2(direction.y(), -direction.x()).normalized());
	}

	for(Vector2 normal : normals){
		double min_proj_poly1 = poly1[0].dot(normal);
		double max_proj_poly1 = poly1[0].dot(normal);
		for(Vector2 v : poly1){
			double cur_proj1 = v.dot(normal);
			if(cur_proj1 < min_proj_poly1){
				min_proj_poly1 = cur_proj1;
			}
			if(cur_proj1 > max_proj_poly1){
				max_proj_poly1 = cur_proj1;
			}
		}
		
		
		double min_proj_poly2 = poly2[0].dot(normal);
		double max_proj_poly2 = poly2[0].dot(normal);
		
		for(Vector2 v : poly2){
			double cur_proj2 = v.dot(normal);
			if(cur_proj2 < min_proj_poly2){
				min_proj_poly2 = cur_proj2;
			}
			if(cur_proj2 > max_proj_poly2){
				max_proj_poly2 = cur_proj2;
			}
		}

		if(max_proj_poly2 < min_proj_poly1 || max_proj_poly1 < min_proj_poly2){
			return false;
		}
	}
	return true;

}
