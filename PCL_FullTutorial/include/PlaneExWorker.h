#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/common/time.h>

#include <boost/algorithm/string.hpp>



class PlaneExWorker
{
private:
  pcl::PointCloud<pcl::PointXYZI>::Ptr p_base_cloud;


public:
  PlaneExWorker(pcl::PointCloud<pcl::PointXYZI>::Ptr p_base_cloud);
  void extract_ground_plane(pcl::PointCloud<pcl::PointXYZI>::Ptr p_plane_cloud);

};
