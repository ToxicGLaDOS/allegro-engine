add_executable(pong main.cpp ball_motion.cpp)

target_link_libraries(pong engine)

file(COPY resources DESTINATION .)
