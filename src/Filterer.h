#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2/imgproc.hpp>


using std::cout;
using std::cin;

using cv::Mat;


#ifndef _PIXEL_
#define _PIXEL_

#define PIXEL(frame, W, x, y) (frame+(y)*3*(W)+(x)*3)

#endif

class Filterer
{
public:
	void BlackAndWhite(Mat&,int,int);
	void BlackHighligtedWhite(Mat&,int w,int h, double limit = -1.0);
	void InvertImage(Mat&,int,int);
	void GaussianBlur(Mat&,int,int,Mat& outputImg, double value = 7.0);
};