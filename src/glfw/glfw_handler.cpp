#include <glfw/glfw_handler.hpp>
namespace glfw {
namespace handler {
GlfwHandler::GlfwHandler(/* args */) {}

GlfwHandler::~GlfwHandler() {}

bool GlfwHandler::Initialize() { return wrapper_->GlfwInit(); }
bool GlfwHandler::MakeWindow(int width, int height, const std::string &title) {
  window_ = wrapper_->GlfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  if (window_ == nullptr) {
    return false;
  }
  wrapper_->GlfwMakeContextCurrent(window_);
  wrapper_->GlfwSwapBuffers(window_);
  return true;
}

void GlfwHandler::SetWindowColor(float red, float green, float blue, float alpha) {
  gl_->GlClearColor(red, green, blue, alpha);
}

bool GlfwHandler::CloseWindow() {
  if (window_ == nullptr) {
    return false;
  }
  return wrapper_->GlfwCloseWindow(window_);
}

}  // namespace handler
}  // namespace glfw