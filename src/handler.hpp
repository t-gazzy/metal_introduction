#ifndef HANDLER_HPP
#define HANDLER_HPP

namespace metal {
namespace handler {
class Handler {
 public:
  Handler(){};
  virtual ~Handler(){};

  virtual int Initialize() = 0;
};
}  // namespace handler
}  // namespace metal

#endif  // HANDLER_HPP
