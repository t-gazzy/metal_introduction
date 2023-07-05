#include <iostream>
#include <memory>

#include "src/glfw_handler.hpp"

int main() {
  std::cout << "hello world" << std::endl;
  auto option = std::make_unique<metal::handler::GlfwInitOptions>();
  auto ptr = std::make_unique<metal::handler::GlfwHandler>();
  auto result = ptr->Initialize(true, std::move(option));
  std::cout << "result: " << result << std::endl;
  return 0;
}