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
  virtual bool MakeWindow(int width, int height, const std::string &title) = 0;
};
}  // namespace glfw::handler

#endif  // GLFW_HANDLER_HPP
