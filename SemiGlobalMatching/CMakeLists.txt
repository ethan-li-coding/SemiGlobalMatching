CMAKE_MINIMUM_REQUIRED(VERSION 2.4)
PROJECT(SemiGlobalMatching)

# opencv library
find_package(OpenCV REQUIRED)
link_directories(${OpenCV_LIBRARY_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/ SRC_FILES)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_FILES})
add_definitions(-std=c++11 -O3)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBRARIES})
