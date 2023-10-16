#include <glad/gl.h>
// `GLFW/glfw3.h` has to be included after `<glad/gl.h>`.
#include <GLFW/glfw3.h>

#include <filesystem>
#include <glad/glad_wrapper.hpp>
#include <glad/reader.hpp>
#include <iostream>
#include <vector>

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

GLuint GladWrapper::LoadProgram() {
  std::string path = std::filesystem::current_path().c_str();
  auto vertex_file = path + "/src/shader/vertex.vert";
  auto fragment_file = path + "/src/shader/fragment.frag";
  ;
  std::cout << "vertex_file: " << vertex_file << std::endl;
  std::cout << "fragment_file: " << fragment_file << std::endl;
  return this->LoadProgram(vertex_file, fragment_file);
}

GLuint GladWrapper::LoadProgram(const std::string &vertex,
                                const std::string &fragment) {
  auto reader = std::make_unique<Reader>();
  auto v_state = reader->Read(vertex);
  auto f_state = reader->Read(fragment);
  if (v_state == std::nullopt) {
    std::cout << "v_state is nullopt" << std::endl;
    return GL_FALSE;
  }

  if (f_state == std::nullopt) {
    std::cout << "f_state is nullopt" << std::endl;
    return GL_FALSE;
  }
  auto program = glCreateProgram();

  // make vertex shader object
  auto vertex_obj = glCreateShader(GL_VERTEX_SHADER);
  auto vertex_src = v_state.value();
  auto vertex_text = vertex_src.data();
  glShaderSource(vertex_obj, 1, &vertex_text, nullptr);
  glCompileShader(vertex_obj);

  if (this->AssertShadeObject(vertex_obj, "vertex_shader")) {
    std::cout << "Assert Vertex Object OK" << std::endl;
    glAttachShader(program, vertex_obj);
  }
  glDeleteShader(vertex_obj);

  // make fragment shader object
  auto fragment_obj = glCreateShader(GL_FRAGMENT_SHADER);
  auto fragment_src = f_state.value();
  auto fragment_text = fragment_src.data();
  glShaderSource(fragment_obj, 1, &fragment_text, nullptr);
  glCompileShader(fragment_obj);

  if (this->AssertShadeObject(fragment_obj, "fragment_shader")) {
    std::cout << "Assert Fragment Object OK" << std::endl;
    glAttachShader(program, fragment_obj);
  }
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

/**
 * Private
 */
GLboolean GladWrapper::AssertShadeObject(GLuint shader,
                                         const std::string &name) {
  GLint status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  if (status == GL_FALSE) {
    std::cout << name << ": "
              << "Link Error" << std::endl;
    return GL_FALSE;
  }

  GLsizei buffer_size;
  glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &buffer_size);

  if (buffer_size > 1) {
    std::vector<GLchar> info_log(buffer_size);
    GLsizei length;
    glGetShaderInfoLog(shader, buffer_size, &length, &info_log.front());
    std::cout << "Info Log " << name << ": " << &info_log.front() << std::endl;
  }
  return static_cast<GLboolean>(status);
}

GLboolean GladWrapper::AssertProgram(GLuint program, const std::string &name) {
  GLint status;
  glGetProgramiv(program, GL_LINK_STATUS, &status);
  if (status == GL_FALSE) {
    std::cout << name << ": "
              << "Link Error" << std::endl;
    return GL_FALSE;
  }

  GLsizei buffer_size;
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &buffer_size);

  if (buffer_size > 1) {
    std::vector<GLchar> info_log(buffer_size);
    GLsizei length;
    glGetProgramInfoLog(program, buffer_size, &length, &info_log.front());
    std::cout << "Info Log " << name << ": " << &info_log.front() << std::endl;
  }
  return static_cast<GLboolean>(status);
}

}  // namespace gl::wrapper