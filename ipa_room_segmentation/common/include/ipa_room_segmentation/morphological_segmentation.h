#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>
#include <list>
#include <vector>

#include <ipa_room_segmentation/watershed_region_spreading.h>
#include <ipa_room_segmentation/contains.h>

class MorphologicalSegmentation
{
public:
	MorphologicalSegmentation();
	//algorithm to segment the map
	void segmentationAlgorithm(cv::Mat& map_to_be_labeled, cv::Mat& segmented_map, double map_resolution_from_subscription, double room_area_factor_lower_limit, double room_area_factor_upper_limit);
};
