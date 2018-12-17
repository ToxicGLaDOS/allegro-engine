#ifndef GEOMETRY_H
#define GEOMETRY_H

#include"vector2.h"

bool pointInRect(Vector2 point, Vector2 rect_pos, Vector2 rect_size);
double length(Vector2 v1, Vector2 v2);
bool pointInCircle(Vector2 point, Vector2 c_pos, double radius);
bool lineCircleIntersection(Vector2 p1, Vector2 p2, Vector2 c_pos, double radius);
bool rectCircleIntersection(Vector2 r_pos, Vector2 r_size, Vector2 c_pos, double radius);

#endif




