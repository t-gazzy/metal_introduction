#ifndef GLFW_GLFW_INTIALIZER_HPP
#define GLFW_GLFW_INTIALIZER_HPP

#include <memory>

#include "handler.hpp"

namespace glfw::handler {
class GlfwInitializer {
 public:
  explicit GlfwInitializer(const std::shared_ptr<Handler> ptr);
  GlfwInitializer(const GlfwInitializer&) = delete;
  GlfwInitializer& operator=(const GlfwInitializer&) = delete;
  GlfwInitializer(GlfwInitializer&&) = delete;
  GlfwInitializer& operator=(GlfwInitializer&&) = delete;
  ~GlfwInitializer();

  bool Initialize() const;

 private:
  std::shared_ptr<Handler> handler_;
};

}  // namespace glfw::handler

#endif GLFW_GLFW_INTIALIZER_HPP