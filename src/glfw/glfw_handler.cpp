#include <glfw/glfw_handler.hpp>
namespace glfw {
namespace handler {
GlfwHandler::GlfwHandler(/* args */) {}

GlfwHandler::~GlfwHandler() {}

bool GlfwHandler::Initialize() { return wrapper_->GlfwInit(); }
bool GlfwHandler::MakeWindow(int width, int height, const std::string &title) {
  auto result = wrapper_->GlfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  return result != nullptr;
}

}  // namespace handler
}  // namespace glfw