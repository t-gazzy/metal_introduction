#include <initializer.hpp>

namespace glfw {
Initializer::Initializer(const std::shared_ptr<handler::Handler> handler)
    : handler_(handler) {}

Initializer::~Initializer() {}

bool Initializer::Initialize() {
    return handler_->Initialize();
}
}  // namespace glfw