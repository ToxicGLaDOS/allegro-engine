#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "image_resource.h"
#include "audio_resource.h"
#include "engine.h"
#include "object.h"
#include "circle_collider.h"

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
