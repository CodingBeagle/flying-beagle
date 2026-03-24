#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <VkBootstrap.h>

#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return 1;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Flying Beagle", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return 1;
    }

    // --- Vulkan Initialization ---

    // Create Vulkan instance
    vkb::InstanceBuilder instanceBuilder;
    auto instanceResult = instanceBuilder
        .set_app_name("Flying Beagle")
        .require_api_version(1, 1, 0)
        .request_validation_layers()
        .use_default_debug_messenger()
        .build();

    if (!instanceResult) {
        std::cerr << "Failed to create Vulkan instance: " << instanceResult.error().message() << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    vkb::Instance vkbInstance = instanceResult.value();

    // Create window surface
    VkSurfaceKHR surface;
    VkResult surfaceResult = glfwCreateWindowSurface(vkbInstance.instance, window, nullptr, &surface);
    if (surfaceResult != VK_SUCCESS) {
        std::cerr << "Failed to create window surface" << std::endl;
        vkb::destroy_instance(vkbInstance);
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    // Select physical device
    vkb::PhysicalDeviceSelector physicalDeviceSelector(vkbInstance);
    auto physicalDeviceResult = physicalDeviceSelector
        .set_surface(surface)
        .select();

    if (!physicalDeviceResult) {
        std::cerr << "Failed to select physical device: " << physicalDeviceResult.error().message() << std::endl;
        vkb::destroy_surface(vkbInstance, surface);
        vkb::destroy_instance(vkbInstance);
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    vkb::PhysicalDevice physicalDevice = physicalDeviceResult.value();

    // Create logical device
    vkb::DeviceBuilder deviceBuilder(physicalDevice);
    auto deviceResult = deviceBuilder.build();

    if (!deviceResult) {
        std::cerr << "Failed to create logical device: " << deviceResult.error().message() << std::endl;
        vkb::destroy_surface(vkbInstance, surface);
        vkb::destroy_instance(vkbInstance);
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    vkb::Device vkbDevice = deviceResult.value();

    // Get graphics queue
    auto graphicsQueueResult = vkbDevice.get_queue(vkb::QueueType::graphics);
    if (!graphicsQueueResult) {
        std::cerr << "Failed to get graphics queue: " << graphicsQueueResult.error().message() << std::endl;
        vkb::destroy_device(vkbDevice);
        vkb::destroy_surface(vkbInstance, surface);
        vkb::destroy_instance(vkbInstance);
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    [[maybe_unused]] VkQueue graphicsQueue = graphicsQueueResult.value();

    std::cout << "Vulkan initialized successfully" << std::endl;

    // --- Main Loop ---

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    // --- Cleanup ---

    // Vulkan cleanup (reverse order of creation)
    vkb::destroy_device(vkbDevice);
    vkb::destroy_surface(vkbInstance, surface);
    vkb::destroy_instance(vkbInstance);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
