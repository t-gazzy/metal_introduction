#include <GLFW/glfw3.h>

#include <fstream>
#include <glad/reader.hpp>
#include <iostream>
#include <optional>
#include <vector>

namespace gl {
Reader::Reader() {}

Reader::~Reader() {}

std::optional<std::vector<GLchar>> Reader::Read(const std::string &filename) {
  std::cout << "Reader" << std::endl;
  std::ifstream file(filename, std::ios::binary);
  if (file.fail()) {
    std::cout << "open file is failed" << std::endl;
    return std::nullopt;
  }
  file.seekg(0L, std::ios::end);
  GLsizei length = static_cast<GLsizei>(file.tellg());
  std::vector<GLchar> buffer = {};
  buffer.resize(length + 1);
  file.seekg(0L, std::ios::beg);
  file.read(buffer.data(), length);
  buffer[length] = '\0';

  std::cout << "buffer ok" << std::endl;
  if (file.fail()) {
    std::cout << "read file is failed" << std::endl;
    file.close();
    return std::nullopt;
  }

  std::cout << "read succeeded" << std::endl;
  file.close();
  return buffer;
}
}  // namespace gl