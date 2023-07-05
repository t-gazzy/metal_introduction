#include "glfw_handler.hpp"
namespace metal {
namespace handler {
GlfwHandler::GlfwHandler(/* args */) {}

GlfwHandler::~GlfwHandler() {}

bool GlfwHandler::Initialize(
    bool is_full_screen, std::unique_ptr<GlfwInitOptions> options = nullptr) {
  // about OpenGL method, go to
  // https://www.glfw.org/docs/3.3/.
  // in Japanese, https://qiita.com/jamaican/items/6dddb3d963bef179b24b.
  // `glfwInit` have to be called at first.
  if (!glfwInit()) {
    return false;
  }
  // confirm OpenGL version
  // `GLFW_CLIENT_API` specifies which client API to create the context for.
  // `GLFW_NO_API` make context creation disable.
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow *window = nullptr;
  std::string title = "SampleWindow";

  if (is_full_screen && options != nullptr) {
    // `glfwGetPrimaryMonitor` returns the primary monitor.
    // primary monitor is where elements like the task bar or global menu bar
    // are located.
    GLFWmonitor *p_monitor = glfwGetPrimaryMonitor();
    // `GLFWvidmode` is https://www.glfw.org/docs/3.3/structGLFWvidmode.html
    const GLFWvidmode *mode = glfwGetVideoMode(p_monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    window = glfwCreateWindow(mode->width, mode->height, options->title.c_str(),
                              NULL, NULL);
  } else if (options != nullptr) {
    glfwWindowHint(GLFW_RESIZABLE, 0);
    window = glfwCreateWindow(options->width, options->height,
                              options->title.c_str(), NULL, NULL);
  } else {
    return false;
  }
  if (!window) {
    return false;
  }
  // make OpenGL or OpenGLES context of specified window current on the calling
  // thread.
  glfwMakeContextCurrent(window);
  // GLFW time
  glfwSetTime(0.0);
  // the number of screen updates to wait from the time glfwSwapBuffers was
  // called before swapping the buffers and returning
  glfwSwapInterval(1);
  return true;
}

}  // namespace handler
}  // namespace metal