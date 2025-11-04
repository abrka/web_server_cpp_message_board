cmake_minimum_required(VERSION 3.2)
project(web_server_cpp_blog_proj)


add_executable(web_server_cpp_blog src/main.cpp)
set_target_properties(web_server_cpp_blog PROPERTIES CXX_STANDARD 20)

add_subdirectory(external/web_server_cpp)
target_link_libraries(web_server_cpp_blog PUBLIC networking_lib::networking_lib)

add_custom_command(
    TARGET web_server_cpp_blog # Or use a custom target like add_custom_target(copy_data ALL)
    POST_BUILD # Or PRE_BUILD, PRE_LINK depending on when you need the copy
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:web_server_cpp_blog>/assets"
)