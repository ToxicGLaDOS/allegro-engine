add_library(engine 
	object.h object.cpp
	sprite.h sprite.cpp
	collider.h collider.cpp
	engine.h
	geometry.h geometry.cpp
	square_collider.h square_collider.cpp
	circle_collider.h circle_collider.cpp
	vector2.h vector2.cpp)

target_link_libraries(engine allegro allegro_image allegro_primitives)

target_include_directories(engine PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

