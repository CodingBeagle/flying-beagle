# src/CMakeLists.txt
# Defines the main executable target

# Add the main executable
add_executable(flying_beagle
    main.cpp
)

# Apply strict compiler options to our code only
apply_compiler_options(flying_beagle)

# Include directories for this target
target_include_directories(flying_beagle
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Link libraries
target_link_libraries(flying_beagle
    PRIVATE glfw
    PRIVATE Vulkan::Vulkan
    PRIVATE vk-bootstrap::vk-bootstrap
)
