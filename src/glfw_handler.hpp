#ifndef GLFW_HANDLER_HPP
#define GLFW_HANDLER_HPP

#include "handler.hpp"

namespace metal {
namespace handler {
class GlfwHandler: public Handler {
 public:
  GlfwHandler();
  // delete copy constructor
  GlfwHandler(const GlfwHandler &) = delete;
  GlfwHandler& operator=(const GlfwHandler&) = delete;
  // delete move constructor
  GlfwHandler(GlfwHandler &&) = delete;
  GlfwHandler& operator=(GlfwHandler&&) = delete;
  ~GlfwHandler();

 private:
  /* data */
};
}  // namespace handler
}  // namespace metal
#endif  // GLFW_HANDLER_HPP