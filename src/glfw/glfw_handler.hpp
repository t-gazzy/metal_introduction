#ifndef GLFW_GLFW_HANDLER_HPP
#define GLFW_GLFW_HANDLER_HPP

#include <GLFW/glfw3.h>

#include <memory>

#include "glfw_wrapper.hpp"
#include "handler.hpp"

namespace glfw::handler {

class GlfwHandler : public Handler {
 public:
  GlfwHandler();
  // delete copy constructor
  GlfwHandler(const GlfwHandler&) = delete;
  GlfwHandler& operator=(const GlfwHandler&) = delete;
  // delete move constructor
  GlfwHandler(GlfwHandler&&) = delete;
  GlfwHandler& operator=(GlfwHandler&&) = delete;
  ~GlfwHandler();

  bool Initialize() override;

 private:
  std::unique_ptr<wrapper::GlfwWrapper> wrapper_ =
      std::make_unique<wrapper::GlfwWrapper>();
};
}  // namespace glfw::handler
#endif  // GLFW_GLFW_HANDLER_HPP