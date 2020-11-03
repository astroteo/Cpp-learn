#include "CloudWrapperTemplate.h"

template <typename T>
CloudWrapperTemplate<T>::CloudWrapperTemplate()
{

}
/*
template <typename T>
void
CloudWrapperTemplate<T>::setCloud(pcl::PointCloud<T> &cloud_)
{
  cloud = cloud_;
}


template <typename T>
void
CloudWrapperTemplate<T>::cloudFromTXT(std::string path, std::string delimiter)
{
  typename pcl::PointCloud<T> pc;
  std::ifstream infile;
  infile.open(path);

  std::string line;
  while (infile >> line)
  {
      std::vector<std::string> cont;
      boost::split(cont, line, boost::is_any_of(delimiter));

      T p_new;


      p_new.x = std::stof(cont[0]);
      p_new.y = std::stof(cont[1]);
      p_new.z = std::stof(cont[2]);
      if (std::is_same<T, pcl::PointXYZI>::value)
      {
        p_new.intensity = std::stof(cont[3])*255;
      }

      pc.push_back(p_new);
      cont.clear();

  }
   return pc;
}


template <typename T>
typename
pcl::PointCloud<T>::Ptr
CloudWrapperTemplate<T>::getCloudPtr()
{
  typename pcl::PointCloud<T>::Ptr pcloud(new pcl::PointCloud<T>);

  *pcloud = cloud;

  return pcloud;
}

template <typename T>
void
CloudWrapperTemplate<T>::putCloudInOrigin()
{
  float cnt = 0;
  float  x_,y_,z_;

  typename pcl::PointCloud<T> new_cloud;

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
    T p_new(p.x - x_,p.y - y_,p.z - z_);
    new_cloud.push_back(p_new);
  }

  cloud.clear();
  cloud = new_cloud;
  new_cloud.clear();

}


*/

/*
template <typename T>
void
CloudWrapperTemplate<T>::printCloudPoints(void)
{
  for(auto p : cloud.points )
  std::cout << p <<std::endl;
}

template <typename T>
void
CloudWrapperTemplate<T>::printCloud(void)
{
  for(auto p : cloud)
  std::cout << p << std::endl;
}

template <typename T>
void
CloudWrapperTemplate<T>::printCloud(int n_points)
{
  for(int i=0; i< n_points; ++i )
  std::cout << cloud[i] << std::endl;

}

template <typename T>
void
CloudWrapperTemplate<T>::save_to_TXT(std::string path)
{
  std::ofstream test_file;

  test_file.open(path);// ../
  for(auto p : cloud.points )
  {
  test_file << p.x <<"," <<p.y << ","<<p.z<<std::endl;

  }
  test_file.close();
}

template <typename T>
void
CloudWrapperTemplate<T>::addCloud(pcl::PointCloud<T>& cloud_add)
{
  cloud += cloud_add;
}


*/
