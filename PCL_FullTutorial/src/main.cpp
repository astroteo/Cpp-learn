#include <iostream>
#include<vector>
#include <thread>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>



#include "CloudWrapper.h"
#include "PlaneExWorker.h"


using namespace std;


boost::shared_ptr<pcl::visualization::PCLVisualizer>
simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud);

boost::shared_ptr<pcl::visualization::PCLVisualizer>
intensityVis (pcl::PointCloud<pcl::PointXYZI>::ConstPtr cloud);

int main()
{

  pcl::PointCloud<pcl::PointXYZ> cloud;

  // Fill in the cloud data
  cloud.width    = 5;
  cloud.height   = 1;
  cloud.is_dense = false;
  cloud.points.resize(cloud.width * cloud.height);

  for (size_t i = 0; i < cloud.points.size (); ++i)
  {
    cloud.points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud.points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud.points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
  }

  CloudWrapper cw;
  cw.setCloud(cloud);

  /* the .txt can be visualized also on cloudCompare */
  std::string path_test = "../Data/test.txt";
  cw.save_to_TXT(path_test);


  CloudWrapper::CloudUtilities cu;
  pcl::PointCloud<pcl::PointXYZ>  cloud_back = cu.cloudFromTXT(path_test);
  cw.setCloud(cloud_back);


  /* Let's load two portions of street */
  pcl::PointCloud<pcl::PointXYZ>  cloud_0 = cu.cloudFromTXT("../Data/sections_0.txt",";");
  pcl::PointCloud<pcl::PointXYZ>  cloud_1 = cu.cloudFromTXT("../Data/sections_1.txt",";");

  CloudWrapper cw_dataset;
  cw_dataset.setCloud(cloud_0);
  cw_dataset.addCloud(cloud_1);

  std::string path_merge = "../Data/sections_0_sections_1.txt";
  cw_dataset.save_to_TXT(path_merge);

  cw_dataset.putCloudInOrigin();
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcloud = cw_dataset.getCloudPtr();
  cout << "stored cloud size in wrapper: "<< pcloud->size()<<endl;
  CloudWrapperI cwI_dataset;

  cwI_dataset.cloudFromTXT("../Data/sections_0.txt",";");
  cwI_dataset.putCloudInOrigin();
  cwI_dataset.scaleIntensity();




  /* point cloud plan extraction with wrapped extractor */
  PlaneExWorker p_ex(cwI_dataset.getCloudPtr());
  pcl::PointCloud<pcl::PointXYZI>::Ptr p_plane_cloud(new pcl::PointCloud<pcl::PointXYZI>);
  p_ex.extract_ground_plane(p_plane_cloud);

  CloudWrapperI cwI_plane(p_plane_cloud);
  pcl::PointXYZI centroid_plane_cloud = cwI_plane.compute_centroid();
  cwI_plane.add(centroid_plane_cloud);

  std::string path_plane_cloud = "../Data/guess_plane_cloud.txt";
  cwI_plane.save_to_TXT(path_plane_cloud);

  Eigen::Matrix3f cov = cwI_plane.compute_covariance_matrix();
  


  bool show_intensity =  true;

  if (show_intensity)
  {

    cout <<"...printing all cloud points..."<< endl;
    cwI_dataset.printCloudPoints();


    cwI_dataset.save_to_TXT("../Data/ciccio_maiale.txt");

    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    viewer = intensityVis((pcl::PointCloud<pcl::PointXYZI>::ConstPtr) cwI_dataset.getCloudPtr());

    while (!viewer->wasStopped ())
    {
      viewer->spinOnce (100);
      boost::this_thread::sleep (boost::posix_time::microseconds (100000));
    }


  }
  else
  {
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    viewer = simpleVis((pcl::PointCloud<pcl::PointXYZ>::ConstPtr ) cw_dataset.getCloudPtr());
    while (!viewer->wasStopped ())
    {
      viewer->spinOnce (100);
      boost::this_thread::sleep (boost::posix_time::microseconds (100000));
    }
  }






  cout << "pCL library correctly loaded,\n and source/headers included \n , instance created \n , cloud saved to .txt \n loaded back from .txt"<<endl;
  return 0;
}


boost::shared_ptr<pcl::visualization::PCLVisualizer> simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}

boost::shared_ptr<pcl::visualization::PCLVisualizer> intensityVis (pcl::PointCloud<pcl::PointXYZI>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZI> point_cloud_color_handler(cloud, "intensity");
  viewer->setBackgroundColor (0, 0, 0);

  viewer->addPointCloud< pcl::PointXYZI >(cloud, point_cloud_color_handler, "id");
  viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "id");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}

/* COMPILE WITH CMake:
  - (mkdir build)
  -cd bulid
  -cmake ..
  -make
*/

/* DIRECTORIES STRUCT:
|-- CMakeLists.txt
 |-- build
 |-- include
 |   \-- CloudWrapper.h
 \-- src
     |-- Cloud.cpp
     \-- main.cpp



http://derekmolloy.ie/hello-world-introductions-to-cmake/#Example_2_A_Project_with_Directories
*/
