cmake_minimum_required(VERSION 3.5)
project(sample)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# add_subdirectory(deps)
find_library(GL
    NAMES gl
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/deps/build
    REQUIRED
)

find_library(GLFW
    NAME glfw.3
    PATHS ${CMAKE_CURRENT_SOURCE_DIR}/libs/macos
    REQUIRED
)

add_executable(${PROJECT_NAME})
add_subdirectory(src)
target_sources(${PROJECT_NAME} PRIVATE main.cpp)

# target_compile_definitions(
#     ${PROJECT_NAME}
#     PRIVATE
#     $<$<CONFIG:Release>:${PROJECT_NAME}_NDEBUG>
#     $<$<CONFIG:Debug>:${PROJECT_NAME}_DEBUG _DEBUG>
# )
# target_compile_options(
#     ${PROJECT_NAME}
#     PRIVATE
#     $<$<CONFIG:Release>:-O3>
#     $<$<CONFIG:Debug>:-O0 -g -Wall -Werror -fsanitize=address>
# )
# target_link_options(
#     ${PROJECT_NAME}
#     PRIVATE
#     $<$<CONFIG:Release>:>
#     $<$<CONFIG:Debug>: -fsanitize=address>
# )
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/internal_include
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    # "-framework Cocoa"
    # "-framework Foundation"
    # "-framework Metal"
    # "-framework QuartzCore"
    ${GLFW}
    ${GL}
)