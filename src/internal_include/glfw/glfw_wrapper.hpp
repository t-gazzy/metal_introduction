#ifndef WRAPPER_GLFW_WRAPPER_HPP
#define WRAPPER_GLFW_WRAPPER_HPP

#include <GLFW/glfw3.h>

namespace glfw::wrapper {

class GlfwWrapper {
 public:
  GlfwWrapper(/* args */);
  // delete copy constructor
  GlfwWrapper(const GlfwWrapper &) = delete;
  GlfwWrapper &operator=(const GlfwWrapper &) = delete;
  // delete move constructor
  GlfwWrapper(GlfwWrapper &&) = delete;
  GlfwWrapper &operator=(GlfwWrapper &&) = delete;
  ~GlfwWrapper();

  /// @brief OpenGL method, go to https://www.glfw.org/docs/3.3/.
  /// in Japanese, https://qiita.com/jamaican/items/6dddb3d963bef179b24b.
  /// This method has to be called at first.
  /// @return result of init
  bool GlfwInit();
  /// @brief Create GLFW window.
  /// @param width The width of the window.
  /// @param height The height of the window.
  /// @param title The string in the title bar.
  /// @param monitor specify the monitor when making the window full screen
  /// mode.
  /// @param share share the resource if set the window's handle.
  /// @return window
  GLFWwindow *GlfwCreateWindow(int width, int height, const char *title,
                               GLFWmonitor *monitor, GLFWwindow *share);
  /// @brief make the window renderring target.
  /// @param window GLFWwindow
  void GlfwMakeContextCurrent(GLFWwindow *window);
  /// @brief replace the window color buffer to another one.
  /// @param window window
  void GlfwSwapBuffers(GLFWwindow *window);
  /// @brief Close the window
  /// @param window 
  /// @return result
  bool GlfwCloseWindow(GLFWwindow *window);
};
}  // namespace glfw::wrapper

#endif  // WRAPPER_GLFW_WRAPPER_HPP