#include <glfw/glfw_handler.hpp>
namespace glfw {
namespace handler {
GlfwHandler::GlfwHandler(/* args */) {}

GlfwHandler::~GlfwHandler() {}

bool GlfwHandler::Initialize() {
  auto result = wrapper_->GlfwInit();
  wrapper_->GlfwSetVersion(4, 1, true, true);
  return result;
}

bool GlfwHandler::MakeWindow(int width, int height, const std::string &title) {
  window_ = wrapper_->GlfwCreateWindow(width, height, title.c_str(), nullptr,
                                       nullptr);
  if (window_ == nullptr) {
    return false;
  }
  wrapper_->GlfwMakeContextCurrent(window_);
  gl_->GlLoad();
  return true;
}

void GlfwHandler::SetWindowColor(float red, float green, float blue,
                                 float alpha) {
  
  gl_->GlClearColor(red, green, blue, alpha);
  gl_->LoadProgram();
}

void GlfwHandler::Swapbuffer() {
  gl_->GlClear();
  gl_->StartUseShader();
  wrapper_->GlfwSwapBuffers(window_);
  wrapper_->GlfwWaitEvent();
}

void GlfwHandler::ClearColor() {
  gl_->GlClear();
  wrapper_->GlfwSwapBuffers(window_);
  wrapper_->GlfwWaitEvent();
}

bool GlfwHandler::CloseWindow() {
  if (window_ == nullptr) {
    return false;
  }
  return wrapper_->GlfwCloseWindow(window_);
}

}  // namespace handler
}  // namespace glfw