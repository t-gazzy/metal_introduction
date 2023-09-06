set(LIB_NAME "gl")
add_library(${LIB_NAME} STATIC src/gl.c)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)