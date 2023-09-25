#include <glfw/glfw_handler.hpp>
#include <initializer.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include <window.hpp>

int main() {
  auto lib = std::make_shared<glfw::handler::GlfwHandler>();
  auto ptr = std::make_unique<glfw::Initializer>(lib);
  bool result = ptr->Initialize();
  if (result) {
    std::cout << "init ok" << std::endl;
  } else {
    std::cout << "init ng" << std::endl;
  }

  auto window = std::make_unique<glfw::Window>(lib);
  bool make_window = window->MakeWindow(640, 480, "Hello from OpenGL");
  if (make_window) {
    std::cout << "make_window ok" << std::endl;
  } else {
    std::cout << "make_window ng" << std::endl;
    return 0;
  }

  window->SetColor(1.0f, 0.0f, 0.0f, 1.0f);

  // std::this_thread::sleep_for(std::chrono::seconds(5));

  while (!window->CloseWindow()) {
    // window->ClearColor();
    // std::cout << "set color ok" << std::endl;
    window->LoopToshow();
  }

  return 0;
}