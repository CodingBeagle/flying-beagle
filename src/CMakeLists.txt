# src/CMakeLists.txt
# Defines the main executable target

# Add the main executable
add_executable(flying_beagle
    main.cpp
)

# Include directories for this target
target_include_directories(flying_beagle
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

# Link libraries
target_link_libraries(flying_beagle
    PRIVATE glfw
)
