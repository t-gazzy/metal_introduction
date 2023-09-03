#include <glfw/glfw_wrapper.hpp>

namespace glfw::wrapper {
GlfwWrapper::GlfwWrapper() {}
GlfwWrapper::~GlfwWrapper() {}

bool GlfwWrapper::GlfwInit() { return glfwInit(); }

GLFWwindow *GlfwWrapper::GlfwCreateWindow(int width, int height,
                                          const char *title,
                                          GLFWmonitor *monitor,
                                          GLFWwindow *share) {
  return glfwCreateWindow(width, height, title, monitor, share);
}

void GlfwWrapper::GlfwMakeContextCurrent(GLFWwindow *window) {
  return glfwMakeContextCurrent(window);
}
}  // namespace glfw::wrapper
