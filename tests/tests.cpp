#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "image_resource.h"
#include "audio_resource.h"
#include "engine.h"
#include "object.h"

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

SCENARIO( "creating objects" ){
	GIVEN( "an object with transform Position: (1.2, 2.5), Rotation: 1.45, Scale: (.5, 1.8)" ){
		double x = 5.1;
		double y = -2.7;
		double rot = 1.45;
		double xScale = .5;
		double yScale = 1.8;
		Object obj = Object(Transform(Vector2(x, y), rot, Vector2(xScale, yScale)), "obj");
		
		REQUIRE(obj.transform().position().x() == Approx(x));
		REQUIRE(obj.transform().position().y() == Approx(y));
		REQUIRE(obj.transform().rotation() == Approx(rot));
		REQUIRE(obj.transform().scale().x() == Approx(xScale));
		REQUIRE(obj.transform().scale().y() == Approx(yScale));

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
	}
}
