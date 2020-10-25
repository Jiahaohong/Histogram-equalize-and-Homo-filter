#include "filter.h"

//中值滤波
cv::Mat middle_filter(cv::Mat &input_img, int size = 3)
{
	int offset = (size-1)/2;
	int cnt1, cnt2, cnt3;
	cv::Mat output_img = input_img.clone();
	//cv::Mat output_img = zero_padding(input_img, offset);
	cv::Mat filter = cv::Mat::zeros(1, size*size, CV_8UC1);
	cv::Mat sorted_filter = cv::Mat::zeros(1, size*size, CV_8UC1);
	int M = output_img.rows;
	int N = output_img.cols;

	for (cnt1 = offset; cnt1 < M-offset; ++cnt1)
	{
		for (cnt2 = offset; cnt2 < N-offset; ++cnt2)
		{
			for (cnt3 = 0; cnt3 < size*size; ++cnt3)
			{
				filter.at<uchar>(0, cnt3) = input_img.at<uchar>(cnt1+(cnt3/size-offset), cnt2+(cnt3%size-offset));
			}
			sorted_filter = seek_sort(filter);
			output_img.at<uchar>(cnt1, cnt2) = sorted_filter.at<uchar>(0, (size*size-1)/2);
		}
	}

	return output_img;
}

cv::Mat zero_padding(cv::Mat &input_img, int size = 1)
{
	int m = input_img.rows;
	int n = input_img.cols;
	cv::Mat output_img = cv::Mat::zeros(m+2*size, n+2*size, CV_8UC1);
	int M = output_img.rows;
	int N = output_img.cols;
	int cnt1, cnt2;

	for (cnt1 = size; cnt1 < M-size; ++cnt1)
	{
		for (cnt2 = size; cnt2 < N-size; ++cnt2)
		{
			output_img.at<uchar>(cnt1, cnt2) = input_img.at<uchar>(cnt1 - size, cnt2 - size);
		}
	}
	
	return output_img;
}

cv::Mat seek_sort(cv::Mat &input_arr)
{
	cv::Mat output_arr = input_arr.clone();
	int N = output_arr.cols;
	int cnt1 = 0, cnt2 = 0;
	uchar gray1, gray2;

	for (cnt1 = 0; cnt1 < N; ++cnt1)
	{
		for (cnt2 = cnt1+1; cnt2 < N; ++cnt2)
		{
			gray1 = output_arr.at<uchar>(0, cnt1);
			gray2 = output_arr.at<uchar>(0, cnt2);
			if (gray2 > gray1)
			{
				output_arr.at<uchar>(0, cnt1) = gray2;
				output_arr.at<uchar>(0, cnt2) = gray1;
			}
		}
	}

	return output_arr;
}

//均值滤波
cv::Mat avrg_filter(cv::Mat &input_img, int size = 3)
{
	cv::Mat output_img = input_img.clone();
	cv::Mat filter = cv::Mat::zeros(1, size*size, CV_8UC1);
	cv::Mat sorted_filter = cv::Mat::zeros(1, size*size, CV_8UC1);
	int M = output_img.rows;
	int N = output_img.cols;
	int offset = (size - 1) / 2;
	int cnt1, cnt2, cnt3;
	double avg;

	for (cnt1 = offset; cnt1 < M - offset; ++cnt1)
	{
		for (cnt2 = offset; cnt2 < N - offset; ++cnt2)
		{
			avg = 0;
			for (cnt3 = 0; cnt3 < size*size; ++cnt3)
			{
				avg += input_img.at<uchar>(cnt1 + (cnt3 / size - offset), cnt2 + (cnt3%size - offset));
			}
			avg /= size * size;
			output_img.at<uchar>(cnt1, cnt2) = (uchar)avg;
		}
	}

	return output_img;
}