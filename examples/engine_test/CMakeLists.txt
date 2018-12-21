add_executable(engine_test main.cpp)

target_link_libraries(engine_test engine)

file(COPY resources DESTINATION .)
