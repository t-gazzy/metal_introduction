#ifndef METAL_HANDLER_HPP
#define METAL_HANDLER_HPP

#include <metal-cpp>

#include "api_handler.hpp"

namespace metal {
namespace handler {
class MetalHandler : public ApiHandler {
 private:
  /* data */
 public:
  MetalHandler(/* args */);
  // delete copy constructor
  MetalHandler(const MetalHandler&) = delete;
  MetalHandler& operator=(const MetalHandler&) = delete;
  // delete move constructor
  MetalHandler(MetalHandler&&) = delete;
  MetalHandler& operator=(MetalHandler&&) = delete;
  ~MetalHandler();
};
}  // namespace handler
}  // namespace metal

#endif  // METAL_HANDLER_HPP