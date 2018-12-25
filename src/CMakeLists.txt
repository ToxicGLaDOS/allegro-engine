add_library(engine 
	object.cpp
	drawable.cpp
	sprite.cpp
	collider.cpp
	engine.h engine.cpp
	camera.cpp
	geometry.cpp
	square_collider.cpp
	circle_collider.cpp
	vector2.cpp
	input.cpp
	image_resource.cpp
	audio_resource.cpp
	exceptions.cpp
	)

target_link_libraries(engine allegro allegro_image allegro_primitives allegro_audio allegro_acodec)

target_include_directories(engine PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

