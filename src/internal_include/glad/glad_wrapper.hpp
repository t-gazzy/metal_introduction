#ifndef GLAD_GRAD_WRAPPER_HPP_
#define GLAD_GRAD_WRAPPER_HPP_

namespace gl::wrapper {

class GladWrapper {
 public:
  GladWrapper();
  GladWrapper(const GladWrapper &) = delete;
  GladWrapper &operator=(const GladWrapper &) = delete;
  GladWrapper(GladWrapper &&) = delete;
  GladWrapper operator=(GladWrapper &&) = delete;
  ~GladWrapper();

  /// @brief set window color
  /// @param red red
  /// @param green green
  /// @param blue blue
  /// @param alpha alpha
  void GlClearColor(float red, float green, float blue, float alpha);
};

}  // namespace gl::wrapper
#endif  // GLAD_GRAD_WRAPPER_HPP_