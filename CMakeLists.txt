cmake_minimum_required(VERSION 3.20)
project(VulkanRenderer)

set(CMAKE_CXX_STANDARD 17)

# Set default paths to your dependencies using environment variables
set(GLFW_DIR "$ENV{GLFW_DIR}")
set(GLM_DIR "$ENV{GLM_DIR}")
set(VULKAN_SDK "$ENV{VULKAN_SDK}")

if (NOT GLFW_DIR OR NOT GLM_DIR OR NOT VULKAN_SDK)
    message(FATAL_ERROR "Please set environment variables GLFW_DIR, GLM_DIR, and VULKAN_SDK.")
endif()

# Find Vulkan
find_package(Vulkan REQUIRED)

# Include directories
include_directories(${GLFW_DIR}/include)
include_directories(${GLM_DIR})
include_directories(${VULKAN_SDK}/Include)

# Link directories
if (WIN32)
    link_directories(${GLFW_DIR}/lib-mingw-w64)
    link_directories(${VULKAN_SDK}/Lib)
elseif (UNIX)
    link_directories(${GLFW_DIR}/lib)
    link_directories(${VULKAN_SDK}/lib)
endif()

add_executable(VulkanRenderer main.cpp)

# Link libraries
if (WIN32)
    target_link_libraries(VulkanRenderer glfw3dll Vulkan::Vulkan gdi32 shell32 ws2_32)
elseif (UNIX)
    target_link_libraries(VulkanRenderer glfw Vulkan::Vulkan pthread dl X11)
endif()

set_target_properties(VulkanRenderer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if (WIN32)
    add_custom_command(TARGET VulkanRenderer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLFW_DIR}/lib-mingw-w64/glfw3.dll"
        $<TARGET_FILE_DIR:VulkanRenderer>
    )
endif()

# Compiler flags for Windows
if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()
