cmake_minimum_required(VERSION 3.10)
project(pygo)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Directory for easier includes
# Anywhere you see include(...) you can check <root>/cmake for that file
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Registers build options that are exposed to cmake
include(CMakeOptions.txt)

# CMake Modules
include(PackConfigurations)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

enable_testing()
