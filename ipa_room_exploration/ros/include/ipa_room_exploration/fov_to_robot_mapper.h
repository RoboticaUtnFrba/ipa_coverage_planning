/*!
 *****************************************************************
 * \file
 *
 * \note
 * Copyright (c) 2016 \n
 * Fraunhofer Institute for Manufacturing Engineering
 * and Automation (IPA) \n\n
 *
 *****************************************************************
 *
 * \note
 * Project name: Care-O-bot
 * \note
 * ROS stack name: autopnp
 * \note
 * ROS package name: ipa_room_exploration
 *
 * \author
 * Author: Florian Jordan, Richard Bormann
 * \author
 * Supervised by: Richard Bormann
 *
 * \date Date of creation: 11.2016
 *
 * \brief
 *
 *
 *****************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer. \n
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution. \n
 * - Neither the name of the Fraunhofer Institute for Manufacturing
 * Engineering and Automation (IPA) nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission. \n
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License LGPL for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************/

#pragma once

// c++ standard libraries
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
// Ros
#include <ros/ros.h>
// service
//#include <cob_map_accessibility_analysis/CheckPerimeterAccessibility.h>
#include <cob_map_accessibility_analysis/map_accessibility_analysis.h>
// OpenCv
#include <opencv/cv.h>
#include <opencv/highgui.h>
// msgs
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/Polygon.h>
// Eigen library
#include <Eigen/Dense>
// specific from this package
#include <ipa_building_navigation/A_star_pathplanner.h>


#define PI 3.14159265359

// Function that provides the functionality that a given field of view (fov) path gets mapped to a robot path by using the given parameters.
// To do so simply a vector operation is applied. If the computed robot pose is not in the free space, another accessible
// point is generated by finding it on the radius around the fov middlepoint s.t. the distance to the last robot position
// is minimized.
// Important: the room map needs to be an unsigned char single channel image, if inaccessible areas should be excluded, provide the inflated map
// robot_to_fov_vector in [m]
// returns robot_path in [m,m,rad]
void mapPath(const cv::Mat& room_map, std::vector<geometry_msgs::Pose2D>& robot_path,
		const std::vector<geometry_msgs::Pose2D>& fov_path, const Eigen::Matrix<float, 2, 1>& robot_to_fov_vector,
		const double map_resolution, const cv::Point2d map_origin, const cv::Point& starting_point);

// computes the field of view center and the radius of the maximum incircle of a given field of view quadrilateral
// fitting_circle_center_point_in_meter this is also considered the center of the field of view, because around this point the maximum radius incircle can be found that is still inside the fov
// fov_resolution resolution of the fov center and incircle computations, in [pixels/m]
void computeFOVCenterAndRadius(const std::vector<Eigen::Matrix<float, 2, 1> >& fov_corners_meter, float& fitting_circle_radius_in_meter,
		Eigen::Matrix<float, 2, 1>& fitting_circle_center_point_in_meter, const double fov_resolution=1000);
