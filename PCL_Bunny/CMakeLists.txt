cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pcd_write)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (pcd_write main.cpp)
list(REMOVE_ITEM PCL_LIBRARIES "vtkproj4")
target_link_libraries (pcd_write ${PCL_LIBRARIES})
