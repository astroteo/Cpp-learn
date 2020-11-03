
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(MY_GRAND_PROJECT)

find_package(PCL 1.3 REQUIRED COMPONENTS common io visualization segmentation filters features)
find_package(Boost 1.67 COMPONENTS program_options REQUIRED )
find_package(VTK)


include_directories(${PCL_INCLUDE_DIRS})
include_directories( ${Boost_INCLUDE_DIR} )

include_directories(include)


link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
message("PCL_LIBRARIES - ${PCL_LIBRARIES}")

set(VTK_DIR "/usr/local/Cellar/vtk/8.1.1/included")
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})


#set(SOURCES src/main.cpp src/CloudWrapper.cpp)
#set(incs  /usr/local/Cellar/pcl/1.8.1_3/include/pcl-1.8)



file(GLOB SOURCES "src/*.cpp")

add_executable(pcl_test src/CloudWrapper.cpp src/CloudWrapperTemplate.cpp src/main.cpp src/PlaneExWorker.cpp)

target_link_libraries(pcl_test ${PCL_LIBRARIES} ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES}${Boost_LIBRARIES}${PCL_VISUALIZATION_LIBRARIES}${PCL_SEGMENTATION_LIBRARIES}${PCL_FEATURE_LIBRARIES})
