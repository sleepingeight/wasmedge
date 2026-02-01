cmake_minimum_required(VERSION 4.2)
project(PrintFunctions LANGUAGES C CXX)

find_package(LLVM REQUIRED CONFIG)

# Optional: helps you see what LLVM CMake exposes
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(main main.cpp)

# LLVM include paths
target_include_directories(main
  PRIVATE
  ${LLVM_INCLUDE_DIRS}
)

# LLVM compile definitions
target_compile_definitions(main
  PRIVATE
  ${LLVM_DEFINITIONS}
)

# Map required LLVM components to libraries
llvm_map_components_to_libnames(LLVM_LIBS
  core
  irreader
  support
)

# Link against LLVM
target_link_libraries(main
  PRIVATE
  ${LLVM_LIBS}
)