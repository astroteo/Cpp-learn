#include "CloudWrapper.h"

CloudWrapper::CloudWrapper()
{

}
CloudWrapper::CloudWrapper(pcl::PointCloud<pcl::PointXYZ>::Ptr pcloud)
{
  cloud = *pcloud;
}
void
CloudWrapper::setCloud(pcl::PointCloud<pcl::PointXYZ> &cloud_)
{
  cloud = cloud_;
}

pcl::PointCloud<pcl::PointXYZ>::Ptr
CloudWrapper::getCloudPtr(void)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcloud(new pcl::PointCloud<pcl::PointXYZ>);

  *pcloud = cloud;

  return pcloud;

}

void
CloudWrapper::printCloudPoints(void)
{
  for(auto p : cloud.points )
  std::cout << p <<std::endl;
}

void
CloudWrapper::printCloud(void)
{
  for(auto p : cloud)
  std::cout << p << std::endl;
}

void
CloudWrapper::printCloud(int n_points)
{
  for(int i=0; i< n_points; ++i )
  std::cout << cloud[i] << std::endl;

}

void
CloudWrapper::save_to_TXT(std::string path)
{
  std::ofstream test_file;

  test_file.open(path);// ../
  for(auto p : cloud.points )
  {
  test_file << p.x <<"," <<p.y << ","<<p.z<<std::endl;

  }
  test_file.close();
}

void
CloudWrapper::addCloud(pcl::PointCloud<pcl::PointXYZ>& cloud_add)
{
  cloud += cloud_add;
}

pcl::PointCloud<pcl::PointXYZ>
CloudWrapper::CloudUtilities::cloudFromTXT(std::string path, std::string delimiter)
  {
    pcl::PointCloud<pcl::PointXYZ> pc;
    std::ifstream infile;
    infile.open(path);

    std::string line;
    while (infile >> line)
    {
        std::vector<std::string> cont;
        boost::split(cont, line, boost::is_any_of(delimiter));

        pcl::PointXYZ p_new;


        p_new.x = std::stof(cont[0]);
        p_new.y = std::stof(cont[1]);
        p_new.z = std::stof(cont[2]);

        std::cout << cont[3] <<std::endl;

        pc.push_back(p_new);
        cont.clear();

    }
     return pc;
  }

void
CloudWrapper::putCloudInOrigin()
{
  float cnt = 0;
  float  x_,y_,z_;

  pcl::PointCloud<pcl::PointXYZ> new_cloud;

  x_ = 0;
  y_ = 0;
  z_ = 0;

  for (auto p : cloud)
  {
    x_ += p.x;
    y_ += p.y;
    z_ += p.z;
    cnt++;
  }

  x_ /= cnt;
  y_ /= cnt;
  z_ /= cnt;
  std::cout<<  "AVG____PARAMS "<<std::endl;
  std::cout<<  x_ << y_ << z_ <<std::endl;


  for (auto p : cloud)
  {
    pcl::PointXYZ p_new(p.x - x_,p.y - y_,p.z - z_);
    new_cloud.push_back(p_new);
  }

  cloud.clear();
  cloud = new_cloud;
  new_cloud.clear();

}
/* cloud wrapper for clouds with intensity */

CloudWrapperI::CloudWrapperI()
{

}
CloudWrapperI::CloudWrapperI(pcl::PointCloud<pcl::PointXYZI>::Ptr pcloud)
{
  cloud = *pcloud;
}

void CloudWrapperI::cloudFromTXT(std::string path, std::string delimiter)
{
  cloud.clear();
  pcl::PointCloud<pcl::PointXYZI> pc;
  std::ifstream infile;
  infile.open(path);

  std::string line;
  while (infile >> line)
  {
      std::vector<std::string> cont;
      boost::split(cont, line, boost::is_any_of(delimiter));

      pcl::PointXYZI p_new;


      p_new.x = std::stof(cont[0]);
      p_new.y = std::stof(cont[1]);
      p_new.z = std::stof(cont[2]);

      p_new.intensity = std::stof(cont[3]);

      pc.push_back(p_new);
      cont.clear();

  }

  cloud = pc;
}
pcl::PointCloud<pcl::PointXYZI>::Ptr
CloudWrapperI::getCloudPtr(void)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr pcloud(new pcl::PointCloud<pcl::PointXYZI>);

  *pcloud = cloud;

  return pcloud;

}

void
CloudWrapperI::add(pcl::PointXYZI p_new)
 {
   cloud.push_back(p_new);
}

void
CloudWrapperI::putCloudInOrigin(void)
{

  float cnt = 0;
  float  x_,y_,z_;

  pcl::PointCloud<pcl::PointXYZI> new_cloud;

  x_ = 0;
  y_ = 0;
  z_ = 0;

  for (auto p : cloud)
  {
    x_ += p.x;
    y_ += p.y;
    z_ += p.z;
    cnt++;
  }

  x_ /= cnt;
  y_ /= cnt;
  z_ /= cnt;
  std::cout<<  "AVG____PARAMS "<<std::endl;
  std::cout<<  x_ << y_ << z_ <<std::endl;


  for (auto p : cloud)
  {
    pcl::PointXYZI p_new;
    p_new.x = p.x - x_;
    p_new.y = p.y - y_;
    p_new.z = p.z - z_;
    p_new.intensity = p.intensity;
    new_cloud.push_back(p_new);
  }

  cloud.clear();
  cloud = new_cloud;
  new_cloud.clear();
}

void
CloudWrapperI::scaleIntensity(void)
{

  pcl::PointCloud<pcl::PointXYZI> new_cloud;

  for (auto p : cloud)
  {

  pcl::PointXYZI p_new;
  p_new.x = p.x;
  p_new.y = p.y;
  p_new.z = p.z;
  p_new.intensity = p.intensity * 255;

  new_cloud.push_back(p_new);

  }

  cloud.clear();
  cloud = new_cloud;
  new_cloud.clear();
}

void
CloudWrapperI::save_to_TXT(std::string path)
{
  std::ofstream test_file;

  test_file.open(path);// ../
  for(auto p : cloud.points )
  {
  test_file << p.x <<"," <<p.y << ","<<p.z<< ","<< p.intensity <<std::endl;

  }
  test_file.close();
}
void
CloudWrapperI::printCloudPoints(void)
{
  for(auto p : cloud.points )
  {
  std::cout << p.intensity << " , "<<p.x <<" , " << p.y << " , " << p.z <<std::endl;
  }
}

pcl::PointXYZI
CloudWrapperI::compute_centroid(void)
{

 //Let's use native pcl function=> using back MB approach
 Eigen::Vector4f centroid_v;
 pcl::compute3DCentroid(cloud,centroid_v);

 pcl::PointXYZI centroid;

 centroid.intensity = 255;
 centroid.x = centroid_v(0);
 centroid.y = centroid_v(1);
 centroid.z = centroid_v(2);

 return centroid;

}

Eigen::Matrix3f
CloudWrapperI::compute_covariance_matrix(void)
{

  Eigen::Vector4f centroid;
  pcl::compute3DCentroid(cloud,centroid);
  Eigen::Matrix3f covariance_matrix;

  computeCovarianceMatrix (cloud,centroid, covariance_matrix);

  return covariance_matrix;

}
