#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
//#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

namespace Renderer {
    class Application {
        public:
            void run() {
                initWindow();
                initVulkan();
                mainLoop();
                cleanup();
            }

        private:
            GLFWwindow* window;
            VkInstance instance;

            // Initializing window with no resize, removing specifying Vulkan context
            void initWindow() {
                glfwInit();

                glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
                glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
            
                window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
            }

            void initVulkan() {
                createInstance();
            }

            // Checking for exit
            void mainLoop() {
                while (!glfwWindowShouldClose(window)) {
                    glfwPollEvents();
                }
            }

            // Neccessary memory cleanup (as per C/C++)
            void cleanup() {
                glfwDestroyWindow(window);

                glfwTerminate();
            }

            void createInstance() {
                // Important Application Info
                VkApplicationInfo appInfo{};
                appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
                appInfo.pApplicationName = "Vulkan Renderer";
                appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
                appInfo.pEngineName = "No Engine";
                appInfo.engineVersion = VK_MAKE_VERSION(1, 0 ,0);
                appInfo.apiVersion = VK_API_VERSION_1_0;

                // Optional info for global extensions/validation layers
                VkInstanceCreateInfo createInfo{};
                createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
                createInfo.pApplicationInfo = &appInfo;

                uint32_t glfwExtensionCount = 0;
                const char** glfwExtensions;

                glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

                createInfo.enabledExtensionCount = glfwExtensionCount;
                createInfo.ppEnabledExtensionNames = glfwExtensions;

                createInfo.enabledLayerCount = 0;
            }

    };
}
int main() {
    Renderer::Application app;

    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}