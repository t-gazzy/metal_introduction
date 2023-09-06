#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <interface/handler.hpp>
#include <memory>
#include <string>

namespace glfw {
class Window {
 public:
  explicit Window(const std::shared_ptr<handler::Handler> handler);
  Window(const Window &) = delete;
  Window &operator=(const Window &) = delete;
  Window(Window &&) = delete;
  Window operator=(Window &&) = delete;
  ~Window();

  bool MakeWindow(int width, int height, const std::string &title);
  void SetColor(float red, float green, float blue, float alpha);
  bool CloseWindow();

 private:
  std::shared_ptr<handler::Handler> handler_;
};
}  // namespace glfw

#endif  // WINDOW_HPP