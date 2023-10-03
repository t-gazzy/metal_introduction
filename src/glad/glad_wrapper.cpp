#include <glad/gl.h>
// `GLFW/glfw3.h` has to be included after `<glad/gl.h>`.
#include <GLFW/glfw3.h>

#include <glad/glad_wrapper.hpp>
#include <iostream>

namespace gl::wrapper {
GladWrapper::GladWrapper() {}
GladWrapper::~GladWrapper() {}

static constexpr GLchar g_vertex_src[] =
    "#version 410 core¥n"
    "in vec4 position;¥n"
    "void main()¥n"
    "{¥n"
    " gl_Position = position;¥n"
    "}¥n";

static constexpr GLchar g_fragment_src[] =
    "#version 410 core¥n"
    "out vec4 fragment;¥n"
    "void main()¥n"
    "{¥n"
    " fragment = vec4(1.0, 0.0, 0.0, 1.0);¥n"
    "}¥n";

bool GladWrapper::GlLoad() { return gladLoadGL(glfwGetProcAddress); }

void GladWrapper::GlClearColor(float red, float green, float blue,
                               float alpha) {
  std::cout << "red: " << red << "green: " << green << "blue: " << blue
            << "alpha: " << alpha << std::endl;
  glClearColor(red, green, blue, alpha);
  std::cout << "OpenGL version" << glGetString(GL_VERSION) << std::endl;
}

void GladWrapper::GlClear() { glClear(GL_COLOR_BUFFER_BIT); }

GLuint GladWrapper::CreateProgram() {
  return this->CreateProgram(g_vertex_src, g_fragment_src);
}

GLuint GladWrapper::CreateProgram(const std::string &vertex_program_text,
                                  const std::string &fragment_program_text) {
  auto program = glCreateProgram();

  // make vertex shader object
  auto vertex_obj = glCreateShader(GL_VERTEX_SHADER);
  auto vertex_src = vertex_program_text.c_str();
  glShaderSource(vertex_obj, 1, &vertex_src, nullptr);
  glCompileShader(vertex_obj);
  glAttachShader(program, vertex_obj);
  glDeleteShader(vertex_obj);

  // make fragment shader object
  auto fragment_obj = glCreateShader(GL_FRAGMENT_SHADER);
  auto fragment_src = fragment_program_text.c_str();
  glShaderSource(fragment_obj, 1, &fragment_src, nullptr);
  glCompileShader(fragment_obj);
  glAttachShader(program, fragment_obj);
  glDeleteShader(fragment_obj);

  // link program object
  glBindAttribLocation(program, 0, "position");
  glBindFragDataLocation(program, 0, "fragment");
  glLinkProgram(program);

  program_ = program;
  return program_;
}

bool GladWrapper::StartUseShader() {
  if (program_ == 0) {
    return false;
  }

  glUseProgram(program_);
  return true;
}

}  // namespace gl::wrapper