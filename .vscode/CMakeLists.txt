cmake_minimum_required(VERSION 3.20)
project(VulkanRenderer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set the paths to your dependencies
set(GLFW_DIR "C:/CLibraries/glfw-3.4.bin.WIN64")
set(GLM_DIR "C:/CLibraries/glm")
set(VULKAN_SDK "C:/VulkanSDK/1.3.290.0")

# Find Vulkan
find_package(Vulkan REQUIRED)

# Include directories
include_directories(${GLFW_DIR}/include)
include_directories(${GLM_DIR})
include_directories(${VULKAN_SDK}/Include)

# Link directories
link_directories(${GLFW_DIR}/lib-vc2019)
link_directories(${VULKAN_SDK}/Lib)

# Add the executable
add_executable(VulkanRenderer main.cpp)

# Link libraries
target_link_libraries(VulkanRenderer glfw3 Vulkan::Vulkan)

# Set the output directory for the executable
set_target_properties(VulkanRenderer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Post-build commands to copy necessary DLLs
add_custom_command(TARGET VulkanRenderer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GLFW_DIR}/lib-vc2019/glfw3.dll"
    $<TARGET_FILE_DIR:VulkanRenderer>
)

# Set compiler flags for Windows
if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()
