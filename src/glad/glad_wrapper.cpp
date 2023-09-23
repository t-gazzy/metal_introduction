#include <glad/gl.h>
// `GLFW/glfw3.h` has to be included after `<glad/gl.h>`.
#include <GLFW/glfw3.h>

#include <glad/glad_wrapper.hpp>
#include <iostream>

namespace gl::wrapper {
GladWrapper::GladWrapper() {}
GladWrapper::~GladWrapper() {}

bool GladWrapper::GlLoad() { return gladLoadGL(glfwGetProcAddress); }

void GladWrapper::GlClearColor(float red, float green, float blue,
                               float alpha) {
  glClearColor(red, green, blue, alpha);
  std::cout << "OpenGL version" << glGetString(GL_VERSION) << std::endl;
  std::cout << "GlClearColor OK" << std::endl;
}

void GladWrapper::GlClear() { glClear(GL_COLOR_BUFFER_BIT); }

}  // namespace gl::wrapper