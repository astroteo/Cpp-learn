#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#include <boost/algorithm/string.hpp>
#include <type_traits>

template <typename T>
class CloudWrapperTemplate{

public:
   pcl::PointCloud<T> cloud;

public:
  CloudWrapperTemplate();
  /*
  void setCloud(pcl::PointCloud<T> &cloud_);
  typename pcl::PointCloud<T>::Ptr getCloudPtr(void);
  void putCloudInOrigin(void);
  void cloudFromTXT(std::string path, std::string delimiter);
  */
  /*
  void printCloudPoints(void);
  void printCloud(void);
  void printCloud(int n_points);
  void save_to_TXT(std::string path);
  void addCloud(pcl::PointCloud<T> &cloud_add);
  void putCloudInOrigin(void);
  */


};
