cmake_minimum_required(VERSION 3.5)
project(metal-cpp)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(GLFW REQUIRED)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp src/glfw_handler.cpp)

target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:Release>:${PROJECT_NAME}_NDEBUG>
    $<$<CONFIG:Debug>:${PROJECT_NAME}_DEBUG _DEBUG>
)
target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:Release>:-O3>
    $<$<CONFIG:Debug>:-O0 -g -Wall -Werror -fsanitize=address>
)
target_link_options(
    ${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:Release>:>
    $<$<CONFIG:Debug>: -fsanitize=address>
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    #${OPENGL_INCLUDE_DIR}
    ${GLFW_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    "-framework Cocoa"
    "-framework Foundation"
    "-framework Metal"
    "-framework QuartzCore"
    ${GLFW_LIBRARIES}
)