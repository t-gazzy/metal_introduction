#include "glfw_wrapper.hpp"

namespace glfw::wrapper {
GlfwWrapper::GlfwWrapper() {}
GlfwWrapper::~GlfwWrapper() {}

bool GlfwWrapper::GlfwInit() { return glfwInit(); }

GLFWWindow *GlfwWrapper::GlfwCreateWindow(int width, int height,
                                          const char *title,
                                          GLFWmonitor *monitor,
                                          GLFWwindow *share) {
  return glfwCreateWindow(width, height, title, monitor, share);
}

void GlfwWrapper::GlfwMakeContextCurrent(GLFWWindow *window) {
  return glfwMakeContextCurrent(window);
}
}  // namespace glfw::wrapper
