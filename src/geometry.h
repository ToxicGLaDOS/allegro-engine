#ifndef GEOMETRY_H
#define GEOMETRY_H

#include"vector2.h"

bool pointInRect(const Vector2& point, const Vector2& rect_pos, const Vector2& rect_size);
double distance(const Vector2& v1, const Vector2& v2);
bool pointInCircle(const Vector2& point, const Vector2& c_pos, double radius);
bool lineCircleIntersection(const Vector2& p1, const Vector2& p2, const Vector2& c_pos, double radius);
bool rectCircleIntersection(const Vector2& r_pos, const Vector2& r_size, const Vector2& c_pos, double radius);
bool rectRectIntersection(const Vector2& r1_pos, const Vector2& r1_size, const Vector2& r2_pos, const Vector2& r2_size);
bool circleCircleIntersection(const Vector2& c1_pos, double r1, const Vector2& c2_pos, double r2);
#endif




