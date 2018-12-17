add_executable(game main.cpp)

target_link_libraries(game engine)

file(COPY resources DESTINATION .)
