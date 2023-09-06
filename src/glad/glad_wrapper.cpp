#include <glad/gl.h>

#include <glad/glad_wrapper.hpp>

namespace gl::wrapper {
GladWrapper::GladWrapper() {}
GladWrapper::~GladWrapper() {}

void GladWrapper::GlClearColor(float red, float green, float blue,
                               float alpha) {
  glClearColor(red, green, blue, alpha);
}

}  // namespace gl::wrapper