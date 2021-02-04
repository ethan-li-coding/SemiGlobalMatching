# CMakeList.txt: SemiGlobalMatching 的 CMake 项目，在此处包括源代码并定义项目特定的逻辑。
cmake_minimum_required(VERSION 3.2)

project(SemiGlobalMatching)

add_definitions(-std=c++11 -O3)

# OpenCV library
find_package(OpenCV REQUIRED)
if (OpenCV_VERSION VERSION_LESS 3.0)
  message(FATAL_ERROR "Error: OpenCV version requires at least 3.0")
endif()
link_directories(${OpenCV_LIBRARY_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/ SRC_FILES)

# 将源代码添加到此项目的可执行文件。
add_executable(${PROJECT_NAME} ${SRC_FILES})

# 链接OpenCV库。
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# TODO: 如有需要，请添加测试并安装目标。
