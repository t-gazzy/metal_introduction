#ifndef GLFW_HANDLER_HPP
#define GLFW_HANDLER_HPP

#include <GLFW/glfw3.h>

#include "handler.hpp"

namespace glfw {
namespace handler {
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

  bool Initialize(bool is_full_screen,
                  std::unique_ptr<GlfwInitOptions> options) override;

 private:
  /* data */
};
}  // namespace handler
}  // namespace glfw
#endif  // GLFW_HANDLER_HPP