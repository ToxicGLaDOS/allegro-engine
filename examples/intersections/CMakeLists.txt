add_executable(intersections main.cpp)

target_link_libraries(intersections engine)

file(COPY resources DESTINATION .)
