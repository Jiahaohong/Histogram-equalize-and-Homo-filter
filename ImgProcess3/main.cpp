#include "common.h"

int main()
{
	//读入图像
	cv::Mat orig_img = cv::imread("lena.jpg");
	int M = orig_img.rows;
	int N = orig_img.cols;

	cv::imshow("orig img", orig_img);

	//转灰度图像
	cv::Mat gray_img;
	cv::cvtColor(orig_img, gray_img, CV_BGR2GRAY);
	cv::imshow("gray img", gray_img);

	//随机种子
	cv::RNG rng(12345);
	int cnt1, cnt2;
	//添加椒盐噪声
	//cv::Mat impulse_img = gray_img.clone();
	//int flag;
	//double SNR = 0.95;
	//for (cnt1 = 0; cnt1 < M; ++cnt1)
	//{
	//	for (cnt2 = 0; cnt2 < N; ++cnt2)
	//	{
	//		flag = rng.uniform(1, 100);
	//		if (flag > 100*SNR)
	//		{
	//			if (flag % 2 == 1)
	//			{
	//				impulse_img.at<uchar>(cnt1, cnt2) = 255;
	//			}
	//			else
	//			{
	//				impulse_img.at<uchar>(cnt1, cnt2) = 0;
	//			}
	//		}
	//	}
	//}
	//cv::imshow("impulse img", impulse_img);

	//中值滤波
	//cv::Mat middle_filted_img3 = middle_filter(impulse_img, 3);
	//cv::imshow("middle 3x3", middle_filted_img3);
	//cv::Mat middle_filted_img5 = middle_filter(impulse_img, 5);
	//cv::imshow("middle 5x5", middle_filted_img5);
	//cv::Mat middle_filted_img7 = middle_filter(impulse_img, 7);
	//cv::imshow("middle 7x7", middle_filted_img7);
	//均值滤波
	//cv::Mat avrg_filted_img3 = avrg_filter(impulse_img, 3);
	//cv::imshow("average 3x3", avrg_filted_img3);
	//cv::Mat avrg_filted_img5 = avrg_filter(impulse_img, 3);
	//cv::imshow("average 5x5", avrg_filted_img5);
	//cv::Mat avrg_filted_img7 = avrg_filter(impulse_img, 3);
	//cv::imshow("average 7x7", avrg_filted_img7);

	//添加高斯噪声
	cv::Mat gauss_img = gray_img.clone();
	double gauss_noise;
	for (cnt1 = 0; cnt1 < M; ++cnt1)
	{
		for (cnt2 = 0; cnt2 < N; ++cnt2)
		{
			gauss_noise = rng.gaussian(10);
			gauss_img.at<uchar>(cnt1, cnt2) += (uchar)gauss_noise;
		}
	}
	cv::imshow("gauss img", gauss_img);

	////均值滤波
	//cv::Mat avrg_filted_img3 = avrg_filter(gauss_img, 3);
	//cv::imshow("average 3x3", avrg_filted_img3);
	//cv::Mat avrg_filted_img5 = avrg_filter(gauss_img, 3);
	//cv::imshow("average 5x5", avrg_filted_img5);
	//cv::Mat avrg_filted_img7 = avrg_filter(gauss_img, 3);
	//cv::imshow("average 7x7", avrg_filted_img7);
	//中值滤波
	cv::Mat middle_filted_img3 = middle_filter(gauss_img, 3);
	cv::imshow("middle 3x3", middle_filted_img3);
	cv::Mat middle_filted_img5 = middle_filter(gauss_img, 5);
	cv::imshow("middle 5x5", middle_filted_img5);
	cv::Mat middle_filted_img7 = middle_filter(gauss_img, 7);
	cv::imshow("middle 7x7", middle_filted_img7);

	cv::waitKey();

	return 0;
}