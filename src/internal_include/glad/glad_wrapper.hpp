#ifndef GLAD_GRAD_WRAPPER_HPP_
#define GLAD_GRAD_WRAPPER_HPP_

#include <string>

namespace gl::wrapper {

class GladWrapper {
 public:
  GladWrapper();
  GladWrapper(const GladWrapper &) = delete;
  GladWrapper &operator=(const GladWrapper &) = delete;
  GladWrapper(GladWrapper &&) = delete;
  GladWrapper &operator=(GladWrapper &&) = delete;
  ~GladWrapper();

  bool GlLoad();
  /// @brief set window color
  /// @param red red
  /// @param green green
  /// @param blue blue
  /// @param alpha alpha
  void GlClearColor(float red, float green, float blue, float alpha);

  /// @brief Clear Color setting
  void GlClear();

  /// @brief Create shader program
  /// @return
  GLuint CreateProgram();

  /// @brief Create shader program
  /// @param vertex_program_text
  /// @param fragment_program_text
  /// @return
  GLuint CreateProgram(const std::string &vertex_program_text,
                       const std::string &fragment_program_text);

  /// @brief start to use shader program.
  /// @return bool
  bool StartUseShader();

 private:
  GLuint program_ = 0;
};

}  // namespace gl::wrapper
#endif  // GLAD_GRAD_WRAPPER_HPP_