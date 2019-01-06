#ifndef GEOMETRY_H
#define GEOMETRY_H

#include"vector2.h"
#include"collision.h"
#include<vector>

bool pointInRect(const Vector2& point, const Vector2& rect_pos, const Vector2& rect_size);
double distance(const Vector2& v1, const Vector2& v2);
bool pointInCircle(const Vector2& point, const Vector2& c_pos, double radius);
bool lineCircleCollision(const Vector2& p1, const Vector2& p2, const Vector2& c_pos, double radius);
bool rectCircleCollision(const Vector2& r_pos, const Vector2& r_size, const Vector2& c_pos, double radius);
bool rectRectCollision(const Vector2& r1_pos, const Vector2& r1_size, const Vector2& r2_pos, const Vector2& r2_size);
bool circleCircleCollision(const Vector2& c1_pos, double r1, const Vector2& c2_pos, double r2);
bool polygonPolygonCollision(const std::vector<Vector2>& poly1, const std::vector<Vector2>&poly2);
Collision minimumTranslationVector(const std::vector<Vector2>& poly1, const std::vector<Vector2>&poly2);
#endif




