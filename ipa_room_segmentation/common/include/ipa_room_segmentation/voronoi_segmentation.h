#include "ros/ros.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#include <list>
#include <vector>
#include <math.h>

#include <ctime>

#define PI 3.14159265

#include <ipa_room_segmentation/watershed_region_spreading.h>
#include <ipa_room_segmentation/contains.h>

class VoronoiSegmentation
{
private:


	//function to draw the generalized voronoi-diagram into a given map, not drawing lines that start or end at black Pixels
	void drawVoronoi(cv::Mat& img, std::vector<std::vector<cv::Point2f> > facets_of_voronoi, cv::Scalar voronoi_color, std::vector<cv::Point> contour,
	        std::vector<std::vector<cv::Point> > hole_contours);


	//function to get the voronoi-diagram drawn into the map
	void createVoronoiGraph(cv::Mat& map_for_voronoi_generation);

public:


	VoronoiSegmentation();


	//the segmentation-algorithm
	void segmentationAlgorithm(const cv::Mat& map_to_be_labeled, cv::Mat& segmented_map,	double map_resolution_from_subscription, double room_area_factor_lower_limit, double room_area_factor_upper_limit);
};
