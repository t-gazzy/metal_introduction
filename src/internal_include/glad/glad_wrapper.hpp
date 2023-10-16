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

  /// @brief Load Shader Object
  /// @return 
  GLuint LoadProgram();

  /// @brief Load Shader Object
  /// @param vertex vertex shader object path
  /// @param fragment fragment shader object path
  /// @return
  GLuint LoadProgram(const std::string &vertex, const std::string &fragment);

  /// @brief start to use shader program.
  /// @return bool
  bool StartUseShader();

 private:
  /// @brief Check Shader object is compilable.
  /// @param shader shader object
  /// @param name name
  /// @return
  GLboolean AssertShadeObject(GLuint shader, const std::string &name);

  /// @brief Check program object is compilable.
  /// @param shader shader object
  /// @param name name
  /// @return
  GLboolean AssertProgram(GLuint shader, const std::string &name);

  GLuint program_ = 0;
};

}  // namespace gl::wrapper
#endif  // GLAD_GRAD_WRAPPER_HPP_