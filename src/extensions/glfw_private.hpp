#ifndef EXTENSIONS_COCOA_WINDOW_HPP
#define EXTENSIONS_COCOA_WINDOW_HPP

#define GLFW_INCLUDE_NONE
#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

/**
 * Both `MacOS.sdk` and `glfw` have type `id`.
 * To avoid compiling error, 
*/
namespace GLFW::Private {
void *GetCocoaWindow(GLFWwindow *window) { return glfwGetCocoaWindow(window); }
}  // namespace GLFW::Private

#endif  // EXTENSIONS_COCOA_WINDOW_HPP