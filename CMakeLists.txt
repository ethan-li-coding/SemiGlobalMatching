# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required(VERSION 3.2)

# # if using vcpkg install OpenCV, set ON. if not set OFF.
# option(USING_VCPKG "use vcpkg install OpenCV" OFF)
# 
# if(USING_VCPKG)
#   # if set environment variable VCPKG_ROOT
#   if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VCPKG_ROOT})
#     set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
#     message(STATUS "set CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
#   # if not set environment variable VCPKG_ROOT set your own vcpkg_root path
#   elseif(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND NOT DEFINED ENV{VCPKG_ROOT})
#     set(CMAKE_TOOLCHAIN_FILE "E:/Software/vcpkg/scripts/buildsystems/vcpkg.cmake") 
#     message(STATUS "set CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")
#   endif()
# endif()

project("SemiGlobalMatching")

# 包含子项目。
add_subdirectory("SemiGlobalMatching")
