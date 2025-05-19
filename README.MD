# Vulkan Renderer
Vulkan renderer built from Khronos Group [tutorial](https://vulkan-tutorial.com/). Compiled with CMake for cross-compatibility.

---

## Prerequisites

1. **CMake** (version 3.20 or higher)
3. **Vulkan SDK** (version 1.3.290.0 or higher)
4. **GLFW** (version 3.4 or higher)
5. **GLM** (any recent version)
6. **C++ Compiler:** (C++17 or higher)
   - **Windows:** MinGW (g++), Visual Studio (cl.exe)
   - **Linux:** g++
   - **Mac:** clang++

---

## Setting Up Environment Variables

### Windows (Command Prompt):
```cmd
setx GLFW_DIR "/path/to/glfw"
setx GLM_DIR "/path/to/glm"
setx VULKAN_SDK "/path/to/vulkan-sdk"
```

### Linux/MacOS
```bash
export GLFW_DIR="/path/to/glfw"
export GLM_DIR="/path/to/glm"
export VULKAN_SDK="/path/to/vulkan-sdk"
```

## Install & Build Instructions

### Clone the repository
```bash
git clone https://github.com/yourusername/Vulkan-Renderer.git
cd Vulkan-Renderer
```

### Configure the build
**Linux/MacOS**
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

**Windows**
```cmd
cmake -G "MinGW Makefiles" -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

### Build the project
```bash
cmake --build .
```