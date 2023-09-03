#ifndef INITIALIZER_HPP_
#define INITIALIZER_HPP_

#include <interface/handler.hpp>
#include <memory>

namespace glfw {
class Initializer {
 public:
  explicit Initializer(const std::shared_ptr<handler::Handler> handler);
  // delete copy constructor
  Initializer(const Initializer &) = delete;
  Initializer &operator=(const Initializer &) = delete;
  // delete move constructor
  Initializer(Initializer &&) = delete;
  Initializer operator=(Initializer &&) = delete;
  ~Initializer();

  bool Initialize();

 private:
  std::shared_ptr<handler::Handler> handler_;
};
}  // namespace glfw

#endif  // INITIALIZER_HPP_