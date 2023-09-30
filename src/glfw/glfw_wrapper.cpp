#include <glfw/glfw_wrapper.hpp>
#include <iostream>

namespace glfw::wrapper {
GlfwWrapper::GlfwWrapper() {}
GlfwWrapper::~GlfwWrapper() {}

static void glfwError(int id, const char *description) {
  std::cout << "Error Occured: " << description << std::endl;
}

bool GlfwWrapper::GlfwInit() {
  glfwSetErrorCallback(&glfwError);
  atexit(glfwTerminate);
  return glfwInit();
}

void GlfwWrapper::GlfwSetVersion(int major_version, int minor_version,
                                 bool is_use_old_profile,
                                 bool is_core_profile) {
  auto is_old_profile = is_use_old_profile == true ? GL_TRUE : GL_FALSE;
  auto is_core = is_core_profile == true ? GLFW_OPENGL_CORE_PROFILE
                                         : GLFW_OPENGL_COMPAT_PROFILE;
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major_version);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor_version);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, is_core_profile);
  glfwWindowHint(GLFW_OPENGL_PROFILE, is_core);
}

GLFWwindow *GlfwWrapper::GlfwCreateWindow(int width, int height,
                                          const char *title,
                                          GLFWmonitor *monitor,
                                          GLFWwindow *share) {
  return glfwCreateWindow(width, height, title, monitor, share);
}

void GlfwWrapper::GlfwMakeContextCurrent(GLFWwindow *window) {
  glfwMakeContextCurrent(window);
  // V-sync
  // it means that sync the framerate with monitor refresh rate. 
  glfwSwapInterval(1);
}

void GlfwWrapper::GlfwSwapBuffers(GLFWwindow *window) {
  glfwSwapBuffers(window);
}

void GlfwWrapper::GlfwWaitEvent() { glfwWaitEvents(); }

bool GlfwWrapper::GlfwCloseWindow(GLFWwindow *window) {
  return glfwWindowShouldClose(window);
}
}  // namespace glfw::wrapper
