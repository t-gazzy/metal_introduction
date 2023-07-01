#include <iostream>
#include <memory>

#include "src/glfw_handler.hpp"

int main() {
  std::cout << "hello world" << std::endl;
  auto ptr = std::make_unique<metal::handler::GlfwHandler>();
  auto result = ptr->Initialize();
  std::cout << "result: " << result << std::endl;
  return 0;
}