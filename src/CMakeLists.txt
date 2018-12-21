add_library(engine 
	object.cpp
	sprite.cpp
	collider.cpp
	engine.h engine.cpp
	camera.cpp
	geometry.cpp
	square_collider.cpp
	circle_collider.cpp
	vector2.cpp)

target_link_libraries(engine allegro allegro_image allegro_primitives)

target_include_directories(engine PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

