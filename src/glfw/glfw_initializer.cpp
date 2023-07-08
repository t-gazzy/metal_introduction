#include "glfw_initializer.hpp"

namespace glfw::handler {
GlfwInitializer::GlfwInitializer(const std::shared_ptr<Handler> ptr)
    : handler_(ptr) {}
GlfwInitializer::~GlfwInitializer() {}

bool GlfwInitializer::Initialize() const {
    return handler_->Initialize();
}
}  // namespace glfw::handler