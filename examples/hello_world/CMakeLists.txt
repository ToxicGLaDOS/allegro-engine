set(build_name hello_world)

add_executable(${build_name} main.cpp)

target_link_libraries(${build_name} engine)

add_custom_command(TARGET ${build_name} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
		   ${CMAKE_CURRENT_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${build_name}>/resources)


