#include <iostream>
#include <memory>

#include <initializer.hpp>
#include <glfw/glfw_handler.hpp>

int main() {

  auto lib = std::make_shared<glfw::handler::GlfwHandler>();
  auto ptr = std::make_unique<glfw::Initializer>(lib);
  bool result = ptr->Initialize();

  if (result) {
    std::cout << "init ok" << std::endl;
  } else {
    std::cout << "init ng" << std::endl;
  }
  
  return 0;
}