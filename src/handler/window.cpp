#include <window.hpp>

namespace glfw {
Window::Window(const std::shared_ptr<handler::Handler> handler)
    : handler_(handler) {}
Window::~Window() {}

bool Window::MakeWindow(int width, int height, const std::string &title) {
    return handler_->MakeWindow(width, height, title);
}

void Window::SetColor(float red, float green, float blue, float alpha) {
    handler_->SetWindowColor(red, green, blue, alpha);
}

void Window::ClearColor() {
    
}

bool Window::CloseWindow() {
    return handler_->CloseWindow();
}
}  // namespace glfw