#pragma once
#ifndef _FILTER_H
#define _FILTER_H

#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/highgui/highgui_c.h>
#include "opencv2/highgui/highgui.hpp"

cv::Mat middle_filter(cv::Mat &input_img, int size);
cv::Mat zero_padding(cv::Mat &input_img, int size);
cv::Mat seek_sort(cv::Mat &input_arr);
cv::Mat avrg_filter(cv::Mat &input_img, int size);

#endif