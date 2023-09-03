#include <window.hpp>

namespace glfw {
Window::Window(const std::shared_ptr<handler::Handler> handler)
    : handler_(handler) {}
Window::~Window() {}

bool Window::MakeWindow(int width, int height, const std::string &title) {
    return handler_->MakeWindow(width, height, title);
}
}  // namespace glfw