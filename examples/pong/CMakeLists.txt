add_executable(pong main.cpp ball_motion.cpp paddle_collider.cpp horz_wall_collider.cpp vert_wall_collider.cpp)

target_link_libraries(pong engine)

file(COPY resources DESTINATION .)
