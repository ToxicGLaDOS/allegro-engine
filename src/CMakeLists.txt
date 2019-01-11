add_library(engine 
	object.cpp
	drawable.cpp
	sprite.cpp
	animated_sprite.cpp
	text.cpp
	collider.cpp
	engine.h engine.cpp
	camera.cpp
	geometry.cpp
	rect_collider.cpp
	circle_collider.cpp
	polygon_collider.cpp
	vector2.cpp
	matrix2x2.cpp
	transform.cpp
	input.cpp
	image_resource.cpp
	audio_resource.cpp
	animation_resource.cpp
	exceptions.cpp
	)

target_link_libraries(engine allegro allegro_image allegro_primitives allegro_audio allegro_acodec allegro_font allegro_ttf stdc++fs)

target_include_directories(engine PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

