#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <memory>
#include <string>

namespace metal {
namespace handler {

struct GlfwInitOptions {
  std::string title = "";
  int width = 0;
  int height = 0;
};

class Handler {
 public:
  Handler(){};
  virtual ~Handler(){};

  virtual bool Initialize(bool is_full_screen,
                          std::unique_ptr<GlfwInitOptions> options) = 0;
};
}  // namespace handler
}  // namespace metal

#endif  // HANDLER_HPP
