#include "PlaneExWorker.h"


PlaneExWorker::PlaneExWorker(pcl::PointCloud<pcl::PointXYZI>::Ptr p_base_cloud_)
{
  p_base_cloud = p_base_cloud_;

}

void
PlaneExWorker::extract_ground_plane(pcl::PointCloud<pcl::PointXYZI>::Ptr p_plane_cloud)
{
  pcl::ExtractIndices<pcl::PointXYZI> extractor;

    // Create the segmentation object
    pcl::SACSegmentation<pcl::PointXYZI> seg;
    // Optional
    seg.setOptimizeCoefficients(true);
    seg.setModelType(pcl::SACMODEL_PLANE);
    seg.setMethodType(pcl::SAC_RANSAC);
    seg.setMaxIterations(1000);
    seg.setDistanceThreshold(0.01);

    int i = 0;
    int nr_points = (int)p_base_cloud->points.size();

    pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients());
    pcl::PointIndices::Ptr inliers(new pcl::PointIndices());
    
    int cntr = 0;
    while (p_base_cloud->points.size() > 0.3 * nr_points && cntr < p_base_cloud->points.size())
    {
        // Segment the largest planar component from the remaining cloud
        seg.setInputCloud(p_base_cloud);
        //pcl::ScopeTime scopeTime("Test loop");
        {
            seg.segment(*inliers, *coefficients);
        }
        if (inliers->indices.size() == 0)
        {
            std::cerr << "Could not estimate a planar model for the given dataset." << std::endl;
            break;
        }

        // Extract the inliers
        extractor.setInputCloud(p_base_cloud);
        extractor.setIndices(inliers);
        extractor.setNegative(false);
        extractor.filter(*p_plane_cloud);
        //std::cerr << "PointCloud representing the planar component: " << p_plane_cloud->width * p_plane_cloud->height << " data points." << std::endl;
        cntr++;
        }


}

  // Create the filtering object
