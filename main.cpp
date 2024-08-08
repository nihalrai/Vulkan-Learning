#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <vulkan/vulkan.h>

#include <iostream>
#include <exception>
#include <cstdlib>

// Building a triangle
class TriangleBuild {
public:
    void run() {
        initVulkan();
        mainLoop();
        cleanup();
    }
private:
    void initVulkan() {

    }

    void mainLoop() {

    }

    void cleanup() {


    }
};

// Builing a window
class VulkanTest {
    GLFWwindow* window;
    uint32_t extensionCount;
    glm::mat4 matrix;
    glm::vec4 vec;
    int WIDTH;
    int HEIGHT;
    decltype(matrix* vec) test;
    

public:
    VulkanTest(int height, int width) : window(nullptr), extensionCount(0), matrix(0), vec(0){
        HEIGHT = height;
        WIDTH = width;
        test = vec * matrix;
    }

    ~VulkanTest() {
        if (window) {
            glfwDestroyWindow(window);
            glfwTerminate();
            window = nullptr;
        }
    }
    void run() {
        init();
        start();
        exit();
    }
private:
    void init(){
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        window = glfwCreateWindow(HEIGHT, WIDTH, "VulkanTest", nullptr, nullptr);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::cout << extensionCount << " extensions supported\n";
    }

    void start() {
        test = matrix * vec;
        while (window && !glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void exit() {
        if (window) {
            glfwDestroyWindow(window);
            glfwTerminate();
            window = nullptr;
        }       
    }
};

int runWindowCreate() {
    try {
        std::unique_ptr<VulkanTest> vulkanTest = std::make_unique<VulkanTest>();
        vulkanTest->run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
    
}

int runTriangleCreate() {
    try {
        std::unique_ptr<TriangleBuild> app = std::make_unique<TriangleBuild> (800, 600);
        app->run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main() {
    // runWindowCreate();
    std::cout << runTriangleCreate();
    return 0;
}