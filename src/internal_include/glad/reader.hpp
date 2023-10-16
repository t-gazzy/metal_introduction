#ifndef UTIL_READER_HPP_
#define UTIL_READER_HPP_

#include <string>

namespace gl {

class Reader {
 public:
  Reader();
  ~Reader();

  Reader(const Reader &) = delete;
  Reader &operator=(const Reader &) = delete;
  Reader(Reader &&) = delete;
  Reader &operator=(Reader &&) = delete;

  std::optional<std::vector<GLchar>> Read(const std::string &filename);
};

}  // namespace glfw::util

#endif  // UTIL_READER_HPP_