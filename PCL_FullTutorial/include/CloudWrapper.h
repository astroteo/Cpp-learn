#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/centroid.h>

#include <boost/algorithm/string.hpp>


class CloudWrapper{

public:
  pcl::PointCloud<pcl::PointXYZ> cloud;

public:
  CloudWrapper();
  CloudWrapper(pcl::PointCloud<pcl::PointXYZ>::Ptr pcloud);

  void setCloud(pcl::PointCloud<pcl::PointXYZ> &cloud_);
  void printCloudPoints(void);
  void printCloud(void);
  void printCloud(int n_points);
  void save_to_TXT(std::string path);
  void addCloud(pcl::PointCloud<pcl::PointXYZ> &cloud_add);
  void putCloudInOrigin(void);

  pcl::PointCloud<pcl::PointXYZ>::Ptr getCloudPtr(void);


public:
  class CloudUtilities{
  public:
    pcl::PointCloud<pcl::PointXYZ> cloudFromTXT(std::string path, std::string delimiter = ",");

  };
};

class CloudWrapperI{

public:
  pcl::PointCloud<pcl::PointXYZI> cloud;

public:
  CloudWrapperI();
  CloudWrapperI(pcl::PointCloud<pcl::PointXYZI>::Ptr pcloud);

  void  cloudFromTXT(std::string path, std::string delimiter = ",");
  void save_to_TXT(std::string path);
  pcl::PointCloud<pcl::PointXYZI>::Ptr getCloudPtr(void);
  void putCloudInOrigin(void);
  void scaleIntensity(void);
  void printCloudPoints(void);
  void add(pcl::PointXYZI p_new);
  pcl::PointXYZI compute_centroid(void);
  Eigen::Matrix3f compute_covariance_matrix();
  //vector <pcl::PointXYZI> compute_bb(void);




  /*
  void setCloud(pcl::PointCloud<pcl::PointXYZI> &cloud_);
  void printCloudPoints(void);

  void printCloud(int n_points);
  void save_to_TXT(std::string path);
  void addCloud(pcl::PointCloud<pcl::PointXYZI> &cloud_add);
  void putCloudInOrigin(void);
  void cloudFromTxt(std::string path, std::string delimiter = ",")
  pcl::PointCloud<pcl::PointXYZI>::Ptr getCloudPtr(void);
  */


};
