#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "image_resource.h"
#include "audio_resource.h"
#include "engine.h"
#include "object.h"
#include "circle_collider.h"
#include "rect_collider.h"
#include "geometry.h"
#include "matrix2x2.h"
#include "polygon_collider.h"
#include "text.h"

SCENARIO( "creating and using Vector2"){
	GIVEN( "a Vector2" ){
		double x = 1.2;
		double y = -6.1;
		Vector2 v = Vector2(x, y);

		WHEN( "we check the x and y" ){
			THEN( "the x and y components are the same as we passed to the ctor" ){
				REQUIRE(v.x() == Approx(x));
				REQUIRE(v.y() == Approx(y));
			}
		}
		WHEN( "we create a copy" ){
			Vector2 copy = v;
			THEN( "the copy has the same x and y" ){
				REQUIRE(copy.x() == Approx(v.x()));
				REQUIRE(copy.y() == Approx(v.y()));
			}
		}
		WHEN( "we check the magnitude" ){
			THEN( "the magnitude is correct" ){
				REQUIRE(v.magnitude() == Approx(6.21691).margin(.002));
			}
		}
		WHEN( "we get a normalized version" ){
			Vector2 normalized = v.normalized();
			THEN( "the vector's magnitude is 1" ){
				REQUIRE(normalized.magnitude() == Approx(1).margin(.002));
			}
			THEN( "the direction remains the same (y/x ratio)" ){
				REQUIRE(v.y() / v.x() == Approx(normalized.y() / normalized.x()).margin(.002));
			}
		}
		WHEN( "normalize the vector" ){
			// We only copy to test against the origial
			Vector2 copy = v;
			v.normalize();
			THEN( "the vector's magnitude is 1" ){
				REQUIRE(v.magnitude() == Approx(1).margin(.002));
			}
			THEN( "the direction remains the same (y/x ratio)" ){
				REQUIRE(copy.y() / copy.x() == Approx(v.y() / v.x()).margin(.002));
			}
		}
		GIVEN( "another Vector2 that is not equal to the first" ){
			double x2 = 28.9;
			double y2 = .223;
			Vector2 v2 = Vector2(x2, y2);

			WHEN( "we check if the vectors are equal" ){
				THEN( "the vectors are not equal" ){
					REQUIRE_FALSE( v == v2 );
				}
			}
			WHEN( "we subtract the first vector from the second" ){
				Vector2 dif = v2 - v;
				THEN( "we get a vector (x2 - x, y2 - y) "){
					REQUIRE(dif.x() == Approx(v2.x() - v.x()));
					REQUIRE(dif.y() == Approx(v2.y() - v.y()));
				}
			}
			WHEN( "we subtract the second vector from the first" ){
				Vector2 dif = v - v2;
				THEN( "we get a vector (x - x2, y - y2) "){
					REQUIRE(dif.x() == Approx(v.x() - v2.x()));
					REQUIRE(dif.y() == Approx(v.y() - v2.y()));
				}
			}
			WHEN( "we add the first vector to the second" ){
				Vector2 sum = v + v2;
				THEN( "we get a vector (x + x2, y + y2)" ){
					REQUIRE(sum.x() == Approx(x + x2));
					REQUIRE(sum.y() == Approx(y + y2));
				}
			}
			WHEN( "we add the second vector to the first" ){
				Vector2 sum = v2 + v;
				THEN( "we get a vector (x2 + x, y2 + y)" ){
					REQUIRE(sum.x() == Approx(x2 + x));
					REQUIRE(sum.y() == Approx(y2 + y));
				}
			}
			WHEN( "we dot the first vector with the second" ){
				double dot = v.dot(v2);
				THEN( "we get a double (x * x2) + (y * y2)" ){
					REQUIRE(dot == Approx((x * x2) + (y * y2)));
				}
			}
			WHEN( "we dot the second vector with the first" ){
				double dot = v2.dot(v);
				THEN( "we get a double (x2 * x) + (y2 * y)" ){
					REQUIRE(dot == Approx((x2 * x) + (y2 * y)));
				}
			}
			WHEN( "we project the first vector onto the second" ){
				Vector2 proj = v.projectOnto(v2);
				THEN ("we get a the proper projection vector"){
					REQUIRE(proj.x() == Approx(1.15134).margin(.002));
					REQUIRE(proj.y() == Approx(0.00917).margin(.002));		
				}
			}
			WHEN( "we project the second vector onto the first" ){
				Vector2 proj = v2.projectOnto(v);
				THEN ("we get a the proper projection vector"){
					REQUIRE(proj.x() == Approx(1.03451).margin(.002));
					REQUIRE(proj.y() == Approx(-5.25874).margin(.002));			
				}
			}
		}
	}
}

SCENARIO( "creating image resources" ){
	GIVEN( "an engine"){
		Engine engine = Engine(100,100,60);
		GIVEN( "a path to a non-existent image"){
			std::string path = "fake.png";
			REQUIRE( path == "fake.png" );
			
			WHEN( "we load the image"){

				THEN( "an exception is thrown"){
					REQUIRE_THROWS(ImageResource(path));
				}
			}

		}
		GIVEN( "a path to a real image" ){
			std::string path = "real.png";
			REQUIRE( path == "real.png" );
			
			WHEN( "we load the image" ){
				THEN( "no exception is thrown" ){
					REQUIRE_NOTHROW(ImageResource(path));
				}
			}	

		}
	}	
}

SCENARIO( "creating audio resources" ){
	GIVEN( "an engine" ){
		Engine engine = Engine(100,100, 60);
		GIVEN( "a path to a non-existent audio file" ){
			std::string path = "fake.wav";
			REQUIRE( path == "fake.wav");

			WHEN( "we load the audio" ){
				THEN( "an exception is thrown" ){
					REQUIRE_THROWS(AudioResource(path));
				}
			}
		}
		GIVEN( "a path to a real audio file" ){
			std::string path = "real.wav";
			REQUIRE( path == "real.wav");

			WHEN( "we load the audio" ){
				THEN( "no exception is thrown" ){
					REQUIRE_NOTHROW(AudioResource(path));
				}
			}
		}

	}
}

SCENARIO( "handling objects" ){
	GIVEN( "an object with transform Position: (1.2, 2.5), Rotation: 1.45, Scale: (.5, 1.8)" ){
		double x = 5.1;
		double y = -2.7;
		double rot = 1.45;
		double xScale = .5;
		double yScale = 1.8;
		std::string name = "obj";
		Object obj = Object(Transform(Vector2(x, y), rot, Vector2(xScale, yScale)), name);
		
		REQUIRE(obj.transform().position().x() == Approx(x));
		REQUIRE(obj.transform().position().y() == Approx(y));
		REQUIRE(obj.transform().rotation() == Approx(rot));
		REQUIRE(obj.transform().scale().x() == Approx(xScale));
		REQUIRE(obj.transform().scale().y() == Approx(yScale));
		REQUIRE(obj.name() == name);

		WHEN( "the object is moved by (5,10)" ){
			obj.moveBy(Vector2(5,10));
			THEN( "the object's position is changed correctly and rotation and scale are unchanged" ){
				REQUIRE(obj.transform().position().x() == Approx(x+5));
				REQUIRE(obj.transform().position().y() == Approx(y+10));
				REQUIRE(obj.transform().rotation() == Approx(rot));
				REQUIRE(obj.transform().scale().x() == Approx(xScale));
				REQUIRE(obj.transform().scale().y() == Approx(yScale));
			}
		}
		
		WHEN( "the object is move to (7, 15)" ){
			obj.moveTo(Vector2(7,15));
			THEN( "the object's position is chaged correctly and rotation and scale are unchanged" ){
				
				REQUIRE(obj.transform().position().x() == Approx(7));
				REQUIRE(obj.transform().position().y() == Approx(15));
				REQUIRE(obj.transform().rotation() == Approx(rot));
				REQUIRE(obj.transform().scale().x() == Approx(xScale));
				REQUIRE(obj.transform().scale().y() == Approx(yScale));
				
			}
		}
		WHEN( "an object is attached to it" ){
			double x = 0;
			double y = 0;
			Object obj2 = Object(Transform(Vector2(x,y)), "obj2");
			double xDiff = obj.transform().position().x() - obj2.transform().position().x() ;
			double yDiff = obj.transform().position().y() - obj2.transform().position().y() ;
			obj2.attach(&obj);

			THEN( "the original object is a parent of the other object (using isParentOf)" ){
				REQUIRE(obj.isParentOf(&obj2));
			}
			THEN( "the other object is not a parent of the original (using isParentOf)" ){
				REQUIRE_FALSE(obj2.isParentOf(&obj));
			}
			THEN( "the original object is a parent of the other object (using parent)" ){
				REQUIRE(obj2.parent() == &obj);
			}
			THEN( "the other object is not a parent of the original (using parent)" ){
				REQUIRE_FALSE(obj.parent() == &obj2);
			}

			WHEN( "we try to find the child with the correct name" ){
				Object* found = obj.findChildWithName("obj2");
				THEN( "the object is the child object" ){
					REQUIRE( found == &obj2 );
				}
			}
			WHEN( "we try to find the child with the wrong name" ){
				Object* found = obj.findChildWithName("fake_name");
				THEN( "the object is NULL" ){
					REQUIRE( found == NULL);
				}
			}
			WHEN( "we get the children" ){
				std::vector<Object*> children = obj.children();
				THEN( "the child is in the vector of children" ){
					REQUIRE(children[0] == &obj2);
				}
			}
			WHEN( "we move the object by (10, -10)" ){
				double xBy = 10;
				double yBy = -10;

				obj.moveBy(Vector2(xBy, yBy));
				THEN( "the child object moves with it" ){
					// Moves the correct distance
					REQUIRE(obj2.transform().position().x() == Approx(x + xBy));
					REQUIRE(obj2.transform().position().y() == Approx(y + yBy));
					// Mantains the same distance difference to its parent
					REQUIRE(obj.transform().position().x() - obj2.transform().position().x() == Approx(xDiff));
					REQUIRE(obj.transform().position().y() - obj2.transform().position().y() == Approx(yDiff));

				}
			}
			WHEN( "we move the object to (-5, 8)" ){
				double xTo = -5;
				double yTo = 8;

				obj.moveTo(Vector2(xTo, yTo));
				THEN( "the child object moves with it" ){
					// Mantains the same distance difference to its parent
					REQUIRE(obj.transform().position().x() - obj2.transform().position().x() == Approx(xDiff));
					REQUIRE(obj.transform().position().y() - obj2.transform().position().y() == Approx(yDiff));
				}
			}
		}
		WHEN( "an object is attached to itself" ){
			THEN( "it throws an error" ){
				REQUIRE_THROWS(obj.attach(&obj));
			}
		}
	}
}

SCENARIO( "creating a camera" ){
	GIVEN( "an engine" ){
		Engine engine = Engine(100,100,60);
		GIVEN( "a camera object at (40.3, -100.8) of size (100,100)" ){
			double x = 40.3;
			double y = -100.8;
			double xSize = 100;
			double ySize = 100;
			std::string name = "camera";
			Camera camera = Camera(Vector2(x,y), Vector2(xSize,ySize), name);

			REQUIRE(camera.transform().position().x() == x);
			REQUIRE(camera.transform().position().y() == y);
			REQUIRE(camera.size().x() == xSize);
			REQUIRE(camera.size().y() == ySize);
			REQUIRE(camera.name() == name);

			WHEN( "we convert (0,0) to world space" ){
				Vector2 worldSpace = camera.cameraToWorldSpace(Vector2(0,0));
				THEN( "the point is equal to the camera's position" ){
					REQUIRE(worldSpace.x() == camera.transform().position().x());
					REQUIRE(worldSpace.y() == camera.transform().position().y());
				}
			}
			WHEN( "we convert (10, 50) to world space" ){
				Vector2 point = Vector2(10,50);
				Vector2 worldSpace = camera.cameraToWorldSpace(point);
				THEN( "the point is cameras position + point (with point.y negated)" ){
					REQUIRE(worldSpace.x() == camera.transform().position().x() + point.x());
					REQUIRE(worldSpace.y() == camera.transform().position().y() - point.y());
				}
			}
			WHEN( "we set the background color to (10, 20, 30)" ){
				unsigned char r = 10, g = 20, b = 30;
				camera.setBackgroundColor(r, g, b);
				unsigned char * color = camera.background();

				THEN( "the cameras background changes to (10, 20, 30)" ){
					REQUIRE(color[0] == r);
					REQUIRE(color[1] == g);
					REQUIRE(color[2] == b);	
				}
			}
		}
	}
}

SCENARIO( "creating circle colliders" ){
	GIVEN( "a circle collider" ){
		double x = 10.7;
		double y = -40.1;
		double radius = 55.2;
		std::string name = "circle1";

		CircleCollider circle = CircleCollider(Vector2(x,y), radius, name);
		circle.calcVertices();
		REQUIRE(circle.transform().position().x() == x);
		REQUIRE(circle.transform().position().y() == y);
		REQUIRE(circle.radius() == radius);
		REQUIRE(circle.name() == name);

		GIVEN( "another circle collider that doesn't collide with the first" ){
			double other_x = 1000;
			double other_y = 2000.4;
			double other_radius = 10.2;
			std::string other_name = "circle2";
			CircleCollider other = CircleCollider(Vector2(other_x, other_y), other_radius, other_name);
			other.calcVertices();
			
			REQUIRE(other.transform().position().x() == other_x);
			REQUIRE(other.transform().position().y() == other_y);
			REQUIRE(other.radius() == other_radius);
			REQUIRE(other.name() == other_name);
			
			WHEN( "we check for collisions" ){
				bool circleCollidesOther = circle.collides(&other);
				bool otherCollidesCircle = other.collides(&circle);

				REQUIRE(circleCollidesOther == otherCollidesCircle);

				THEN( "they don't collide" ){
					REQUIRE(circleCollidesOther == false);
					REQUIRE(otherCollidesCircle == false);
				}
			}
			WHEN( "we move the other collider to collide with the first" ){
				other.moveTo(Vector2(circle.transform().position().x() + 40, circle.transform().position().y() + 40));
				other.calcVertices();

				THEN( "they collide" ){
					REQUIRE(circle.collides(&other));
					REQUIRE(other.collides(&circle));
				}
			}
		}

		GIVEN( "another circle collider that does collide with the first" ){
			double other_x = 65;
			double other_y = -90;
			double other_radius = 40.5;
			std::string other_name = "circle2";
			CircleCollider other = CircleCollider(Vector2(other_x, other_y), other_radius, other_name);
			other.calcVertices();
			
			REQUIRE(other.transform().position().x() == other_x);
			REQUIRE(other.transform().position().y() == other_y);
			REQUIRE(other.radius() == other_radius);
			REQUIRE(other.name() == other_name);
			
			WHEN( "we check for collisions" ){
				bool circleCollidesOther = circle.collides(&other);
				bool otherCollidesCircle = other.collides(&circle);

				REQUIRE(circleCollidesOther == otherCollidesCircle);

				THEN( "they do collide" ){
					REQUIRE(circleCollidesOther == true);
					REQUIRE(otherCollidesCircle == true);
				}
			}
			
			WHEN( "we move the other collider to not collide with the first" ){
				other.moveTo(Vector2(circle.transform().position().x() + 400, circle.transform().position().y() + 300));
				other.calcVertices();

				THEN( "they collide" ){
					REQUIRE_FALSE(circle.collides(&other));
					REQUIRE_FALSE(other.collides(&circle));
				}
			}

		}

		GIVEN( "another circle collider that is contained in the first" ){
			double other_x = 10.7;
			double other_y = -40.1;
			double other_radius = 10;
			std::string other_name = "circle2";
			CircleCollider other = CircleCollider(Vector2(other_x, other_y), other_radius, other_name);
			other.calcVertices();
			
			REQUIRE(other.transform().position().x() == other_x);
			REQUIRE(other.transform().position().y() == other_y);
			REQUIRE(other.radius() == other_radius);
			REQUIRE(other.name() == other_name);
			
			WHEN( "we check for collisions" ){
				bool circleCollidesOther = circle.collides(&other);
				bool otherCollidesCircle = other.collides(&circle);

				REQUIRE(circleCollidesOther == otherCollidesCircle);

				THEN( "they do collide" ){
					REQUIRE(circleCollidesOther == true);
					REQUIRE(otherCollidesCircle == true);
				}
			}
		}
	}
}


SCENARIO( "creating rect colliders" ){
	GIVEN( "a rect collider" ){
		double x = -15.3;
		double y = -7.1;
		double xSize = 18.1;
		double ySize = 50.83;
		std::string name = "rect1";
		RectCollider rect = RectCollider(Transform(Vector2(x,y)), Vector2(xSize, ySize), name);
		rect.calcVertices();

		REQUIRE(rect.transform().position().x() == x);
		REQUIRE(rect.transform().position().y() == y);
		REQUIRE(rect.size().x() == xSize);
		REQUIRE(rect.size().y() == ySize);
		REQUIRE(rect.name() == name);

		GIVEN( "another rect collider that collides with the first" ){
			double other_x = -13.5;
			double other_y = 0;
			double other_xSize = 20.2;
			double other_ySize = 70.9;
			std::string other_name = "rect2";
			RectCollider rect2 = RectCollider(Transform(Vector2(other_x,other_y)), Vector2(other_xSize, other_ySize), other_name);
			rect2.calcVertices();

			REQUIRE(rect.transform().position().x() == x);
			REQUIRE(rect.transform().position().y() == y);
			REQUIRE(rect.size().x() == xSize);
			REQUIRE(rect.size().y() == ySize);
			REQUIRE(rect.name() == name);

			WHEN( "we see if they collide" ){
				bool r1Collidesr2 = rect.collides(&rect2);
				bool r2Collidesr1 = rect2.collides(&rect);

				REQUIRE(r1Collidesr2 == r2Collidesr1);

				THEN( "they do collide" ){
					REQUIRE(r1Collidesr2);
					REQUIRE(r2Collidesr1);
				}
			}
			WHEN( "we move the second collider so they don't collide" ){
				rect2.moveBy(Vector2(100, 100));
				rect2.calcVertices();
				bool r1Collidesr2 = rect.collides(&rect2);
				bool r2Collidesr1 = rect2.collides(&rect);

				REQUIRE(r1Collidesr2 == r2Collidesr1);

				THEN( "they no longer collide" ){

					REQUIRE_FALSE(r1Collidesr2);
					REQUIRE_FALSE(r2Collidesr1);
				}
			}
		}

		GIVEN( "another rect collider that does not collide with the first" ){
			double other_x = 100.5;
			double other_y = 70;
			double other_xSize = 20.2;
			double other_ySize = 70.9;
			std::string other_name = "rect2";
			RectCollider rect2 = RectCollider(Transform(Vector2(other_x,other_y)), Vector2(other_xSize, other_ySize), other_name);
			rect2.calcVertices();

			REQUIRE(rect.transform().position().x() == x);
			REQUIRE(rect.transform().position().y() == y);
			REQUIRE(rect.size().x() == xSize);
			REQUIRE(rect.size().y() == ySize);
			REQUIRE(rect.name() == name);

			WHEN( "we see if they collide" ){
				bool r1Collidesr2 = rect.collides(&rect2);
				bool r2Collidesr1 = rect2.collides(&rect);

				REQUIRE(r1Collidesr2 == r2Collidesr1);

				THEN( "they don't collide" ){
					REQUIRE_FALSE(r1Collidesr2);
					REQUIRE_FALSE(r2Collidesr1);
				}
			}
			WHEN( "we move the second collider so they do collide" ){
				// Move it to the same position as the first collider
				// with a little offset
				rect2.moveTo(Vector2(x + 10, y - 20));
				rect2.calcVertices();
				bool r1Collidesr2 = rect.collides(&rect2);
				bool r2Collidesr1 = rect2.collides(&rect);

				REQUIRE(r1Collidesr2 == r2Collidesr1);

				THEN( "they now collide" ){

					REQUIRE(r1Collidesr2);
					REQUIRE(r2Collidesr1);
				}
			}
		}

		GIVEN( "another rect collider that is contained within the first" ){
			double other_x = -15.3;
			double other_y = -7.1;
			double other_xSize = 1.4;
			double other_ySize = 2.5;
			std::string other_name = "rect2";
			RectCollider rect2 = RectCollider(Transform(Vector2(other_x,other_y)), Vector2(other_xSize, other_ySize), other_name);
			rect2.calcVertices();

			WHEN( "we see if they collide" ){
				bool r1Collidesr2 = rect.collides(&rect2);
				bool r2Collidesr1 = rect2.collides(&rect);

				REQUIRE(r1Collidesr2 == r2Collidesr1);

				THEN( "they collide" ){
					REQUIRE(r1Collidesr2);
					REQUIRE(r2Collidesr1);
				}
			}
		}
	}
}

SCENARIO( "creating an engine" ){
	GIVEN( "an engine with a (100, 100) display at 60 FPS" ){
		int width = 100;
		int height = 100;
		int fps = 60;
		Engine engine = Engine(width, height, fps);
		
		REQUIRE(engine.screenWidth() == width);
		REQUIRE(engine.screenHeight() == height);
		REQUIRE(engine.camera() == NULL);
		REQUIRE_FALSE(engine.input() == NULL);

		GIVEN( "a camera of the same size" ){
			Camera camera = Camera(Transform(Vector2(0, 0)), Vector2(width, height), "camera");
			WHEN( "the camera is registered" ){
				engine.register_camera(&camera);
				THEN( "the camera is stored in engine" ){
					REQUIRE(engine.camera() == &camera);
				}
			}
		}
	}
}

SCENARIO( "geometry functions" ){
	GIVEN( "a rectangle and point within it" ){
		Vector2 point = Vector2(15.01, 20.9);
		Vector2 pos = Vector2(14.2, 19.8);
		Vector2 size = Vector2(10.1, 18.6);

		WHEN( "we check if point in rect" ){
			bool inRect = pointInRect(point, pos, size);
			THEN( "the point is in the rect" ){
				REQUIRE(inRect);
			}
		}
	}
	GIVEN( "a rectangle and point not in it" ){
		Vector2 point = Vector2(-12, -2.9);
		Vector2 pos = Vector2(14.2, 19.8);
		Vector2 size = Vector2(10.1, 18.6);

		WHEN( "we check if point in rect" ){
			bool inRect = pointInRect(point, pos, size);
			THEN( "the point is not in the rect" ){
				REQUIRE_FALSE(inRect);
			}
		}
	}
	GIVEN( "two points" ){
		double x1 = 10.2;
		double y1 = 4.6;
		double x2 = -14.8;
		double y2 = -10;

		Vector2 point1 = Vector2(x1, y1);
		Vector2 point2 = Vector2(x2, y2);

		WHEN( "we check the distance between them" ){
			double aToB = distance(point1, point2);
			double bToA = distance(point2, point1);
			
			THEN( "distance from pt1 to pt2 = pt2 to pt1" ){
				REQUIRE(aToB == bToA);
			}
			THEN( "the distance is equal to sqrt((x1-x2)^2 + (y1-y2)^2)" ){
				REQUIRE(aToB == Approx(sqrt(pow(x1-x2,2) + pow(y1-y2,2))));
			}
		}
	}
	GIVEN( "a circle and a point within it" ){
		Vector2 point = Vector2(12.2, -10);
		Vector2 pos = Vector2(11, -9);
		double radius = 4;

		WHEN( "we check if the point is in the circle" ){
			bool inCircle = pointInCircle(point, pos, radius);

			THEN( "the point is in the radius" ){
				REQUIRE(inCircle);
			}
		}
	}
	GIVEN( "a circle and a point not contained within it" ){
		Vector2 point = Vector2(15, -16);
		Vector2 pos = Vector2(11, -9);
		double radius = 4;

		WHEN( "we check if the point is in the circle" ){
			bool inCircle = pointInCircle(point, pos, radius);

			THEN( "the point is in the radius" ){
				REQUIRE_FALSE(inCircle);
			}
		}
	}
	GIVEN( "two polygons that collide" ){
		std::vector<Vector2> poly1;
		std::vector<Vector2> poly2;

		// A triangle
		poly1.push_back(Vector2(-10, 0));
		poly1.push_back(Vector2(10, 0));
		poly1.push_back(Vector2(0, 10));

		// Same triangle but up three units
		poly2.push_back(Vector2(-10, 3));
		poly2.push_back(Vector2(10, 3));
		poly2.push_back(Vector2(0, 13));

		WHEN( "we see if they collide" ){
			bool p1CollidesP2 = polygonPolygonCollision(poly1, poly2);
			bool p2CollidesP1 = polygonPolygonCollision(poly2, poly1);

			THEN( "order doesn't matter" ){
				REQUIRE(p1CollidesP2 == p2CollidesP1);
			}
			THEN( "they collide" ){
				REQUIRE(p1CollidesP2);
			}
		}
	}
	GIVEN( "two polygons that don't collides" ){
		std::vector<Vector2> poly1;
		std::vector<Vector2> poly2;

		// A triangle
		poly1.push_back(Vector2(-10, 0));
		poly1.push_back(Vector2(10, 0));
		poly1.push_back(Vector2(0, 10));

		// Same triangle but up 20 units
		poly2.push_back(Vector2(-10, 20));
		poly2.push_back(Vector2(10, 20));
		poly2.push_back(Vector2(0, 40));

		WHEN( "we see if they collide" ){
			bool p1CollidesP2 = polygonPolygonCollision(poly1, poly2);
			bool p2CollidesP1 = polygonPolygonCollision(poly2, poly1);

			THEN( "order doesn't matter" ){
				REQUIRE(p1CollidesP2 == p2CollidesP1);
			}
			THEN( "they don't collide" ){
				REQUIRE_FALSE(p1CollidesP2);
			}
		}
	}
}

SCENARIO( "transforming points with matrix2x2" ){
	GIVEN( "a point (1,0)" ){
		Vector2 point = Vector2(1,0);

		WHEN( "the point is rotated by 90 degrees" ){
			Vector2 rotated = Matrix2x2::rotate(point, M_PI/2);
			THEN( "the point is (0, 1)"){
				// We need a margin because we are comparing to 0
				// and by default the approx function uses a percentage change
				// but any percent of 0 is 0...
				REQUIRE(rotated.x() == Approx(0).margin(0.00001));
				REQUIRE(rotated.y() == Approx(1));
			}
		}
		WHEN( "the point is rotated by -90 degrees" ){
			Vector2 rotated = Matrix2x2::rotate(point, -M_PI/2);
			THEN( "the point is (0, -1)"){
				REQUIRE(rotated.x() == Approx(0).margin(0.00001));
				REQUIRE(rotated.y() == Approx(-1));
			}
		}
		WHEN( "the point is rotated by 180 degrees" ){
			Vector2 rotated = Matrix2x2::rotate(point, M_PI);
			THEN( "the point is (-1, 0)"){
				REQUIRE(rotated.x() == Approx(-1));
				REQUIRE(rotated.y() == Approx(0).margin(0.00001));
			}
		}
		WHEN( "we rotate the point by 360 degress" ){
			Vector2 rotated = Matrix2x2::rotate(point, 2*M_PI);
			THEN( "the point is (1, 0)"){
				REQUIRE(rotated.x() == Approx(1));
				REQUIRE(rotated.y() == Approx(0).margin(0.00001));
			}
		}
		WHEN( "we rotate the point then rotate it by the negative" ){
			double rotation = 2.45;
			Vector2 rotated = Matrix2x2::rotate(point, rotation);
			rotated = Matrix2x2::rotate(rotated, -rotation);
			THEN( "the point is (-1, 0)"){
				REQUIRE(rotated.x() == Approx(point.x()));
				REQUIRE(rotated.y() == Approx(point.y()));
			}
		}
	}
	GIVEN( "a point (1,1)" ){
		Vector2 point = Vector2(1,1);

		WHEN( "the point is scaled by (1,1)" ){
			Vector2 scaled = Matrix2x2::scale(point, 1, 1);
			THEN( "the point is the same" ){
				REQUIRE(point.x() == Approx(scaled.x()));
				REQUIRE(point.y() == Approx(scaled.y()));
			}
		}
		WHEN( "the point is scaled by (-2.5, 7.8)" ){
			Vector2 scaled = Matrix2x2::scale(point, -2.5, 7.8);
			THEN( "the point is the same" ){
				REQUIRE(scaled.x() == Approx(-2.5));
				REQUIRE(scaled.y() == Approx(7.8));
			}
		}
		WHEN( "the point is scaled and then scaled by the opposite" ){
			double xScale = 6.2;
			double yScale = -10.2;
			Vector2 scaled = Matrix2x2::scale(point, xScale, yScale);
			scaled = Matrix2x2::scale(scaled, 1/xScale, 1/yScale);

			THEN( "the point is the same" ){
				REQUIRE(point.x() == Approx(scaled.x()));
				REQUIRE(point.y() == Approx(scaled.y()));
			}
		}
	}
}

SCENARIO( "creating and colliding polygon colliders" ){
	GIVEN( "a polygon" ){
		std::vector<Vector2> poly1;

		// A triangle
		poly1.push_back(Vector2(-10, -10));
		poly1.push_back(Vector2(10, -10));
		poly1.push_back(Vector2(0, 10));

		double x = 1.2;
		double y = .5;
		std::string name = "poly1";

		PolygonCollider poly1_collider = PolygonCollider(Transform(Vector2(x, y)), poly1, name); 
		poly1_collider.calcVertices();

		REQUIRE(poly1_collider.transform().position().x() == Approx(x));
		REQUIRE(poly1_collider.transform().position().y() == Approx(y));
		// TODO: Figure out why it thinks there is no opertator==
		//REQUIRE(poly1_collider.vertices() == poly1);
		REQUIRE(poly1_collider.name() == name);

		GIVEN( "another polygon that collides with the first" ){
			std::vector<Vector2> poly2;
			// Same triangle
			poly2.push_back(Vector2(-10, -10));
			poly2.push_back(Vector2(10, -10));
			poly2.push_back(Vector2(0, 10));
			
			double other_x = 2;
			double other_y = 5;
			std::string other_name = "poly2";

			PolygonCollider poly2_collider = PolygonCollider(Transform(Vector2(other_x, other_y)), poly2, other_name); 
			poly2_collider.calcVertices();

			WHEN( "we see if they collide" ){
				bool p1CollidesP2 = poly1_collider.collides(&poly2_collider);
				bool p2CollidesP1 = poly2_collider.collides(&poly1_collider);

				THEN( "order doesn't matter" ){
					REQUIRE(p1CollidesP2 == p2CollidesP1);
				}
				THEN( "they collide" ){
					REQUIRE(p1CollidesP2);
				}
			}
		}
		GIVEN( "another polygon that doesn't collide with the first" ){
			std::vector<Vector2> poly2;
			// Same triangle
			poly2.push_back(Vector2(-10, -10));
			poly2.push_back(Vector2(10, -10));
			poly2.push_back(Vector2(0, 10));
			
			double other_x = 22.2;
			double other_y = -6.7;
			std::string other_name = "poly2";

			PolygonCollider poly2_collider = PolygonCollider(Transform(Vector2(other_x, other_y)), poly2, other_name); 
			poly2_collider.calcVertices();

			WHEN( "we see if they collide" ){
				bool p1CollidesP2 = poly1_collider.collides(&poly2_collider);
				bool p2CollidesP1 = poly2_collider.collides(&poly1_collider);

				THEN( "order doesn't matter" ){
					REQUIRE(p1CollidesP2 == p2CollidesP1);
				}
				THEN( "they don't collide" ){
					REQUIRE_FALSE(p1CollidesP2);
				}
			}
		}
	}
}

SCENARIO( "creating texts" ){
	GIVEN( "an engine"){
		Engine engine = Engine(100,100,60);
		double x = 1.2;
		double y = 5.3;
		std::string text = "this is text";
		int size = 12;
		unsigned char r = 65, g = 23, b = 221;
		std::string name= "text";
		GIVEN( "a path to a non-existent font"){
			std::string path = "fake.ttf";
			
			WHEN( "we load the text"){
				THEN( "an exception is thrown"){
					REQUIRE_THROWS(Text(Transform(Vector2(x,y)), text, path, size, r, g, b, name));
				}
			}

		}
		GIVEN( "a path to a real font" ){
			std::string path = "real.ttf";
			

			WHEN( "we load the text" ){
				THEN( "no exception is thrown" ){
					REQUIRE_NOTHROW(Text(Transform(Vector2(x,y)), text, path, size, r, g, b, name));
				}
				THEN( "all the variables are the same" ){
					Text t = Text(Transform(Vector2(x,y)), text, path, size, r, g, b, name);
					unsigned char* color = t.color();
					REQUIRE(t.transform().position().x() == Approx(x));
					REQUIRE(t.transform().position().y() == Approx(y));
					REQUIRE(t.text() == text);
					REQUIRE(t.size() == size);
					REQUIRE(color[0] == r);
					REQUIRE(color[1] == g);
					REQUIRE(color[2] == b);
					REQUIRE(t.name() == name);
				}
			}

		}
	}
}
