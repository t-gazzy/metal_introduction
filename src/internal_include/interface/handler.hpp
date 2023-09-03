#ifndef GLFW_HANDLER_HPP
#define GLFW_HANDLER_HPP

#include <memory>
#include <string>

namespace glfw::handler {

class Handler {
 public:
  Handler(){};
  virtual ~Handler(){};

  virtual bool Initialize() = 0;
};
}  // namespace glfw::handler

#endif  // GLFW_HANDLER_HPP
