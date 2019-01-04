#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "image_resource.h"
#include "audio_resource.h"
#include "engine.h"

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
