#include <glfw_handler.hpp>
namespace glfw {
namespace handler {
GlfwHandler::GlfwHandler(/* args */) {}

GlfwHandler::~GlfwHandler() {}

bool GlfwHandler::Initialize() { return wrapper_->GlfwInit(); }

}  // namespace handler
}  // namespace glfw