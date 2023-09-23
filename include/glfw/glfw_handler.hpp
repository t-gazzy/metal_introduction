#ifndef GLFW_GLFW_HANDLER_HPP
#define GLFW_GLFW_HANDLER_HPP

#include <GLFW/glfw3.h>

#include <glad/glad_wrapper.hpp>
#include <glfw/glfw_wrapper.hpp>
#include <interface/handler.hpp>
#include <memory>

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
  bool MakeWindow(int width, int height, const std::string& title) override;
  void SetWindowColor(float red, float green, float blue, float alpha) override;
  void ClearColor() override;
  bool CloseWindow() override;

 private:
  std::unique_ptr<wrapper::GlfwWrapper> wrapper_ =
      std::make_unique<wrapper::GlfwWrapper>();
  std::unique_ptr<gl::wrapper::GladWrapper> gl_ =
      std::make_unique<gl::wrapper::GladWrapper>();
  GLFWwindow* window_ = nullptr;
};
}  // namespace glfw::handler
#endif  // GLFW_GLFW_HANDLER_HPP