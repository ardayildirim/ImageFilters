#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "vec3.h"

using std::cout;
using std::cin;

using cv::Mat;


#ifndef PIXEL

#define PIXEL(frame, W, x, y) (frame+(y)*3*(W)+(x)*3)

#endif

#ifndef IN
#define IN(x,y,w,h) ((x >= 0) && (x < w) && (y >= 0) && (y < h))

#endif

class Filterer
{
public:
	void WriteToFile(const Mat& img, const std::string& fileName);
	void BlackAndWhite(Mat&,int w,int h);
	void BlackHighligtedWhite(Mat&,int w,int h, double limit = -1.0);
	void InvertImage(Mat&,int w ,int h);
	void GaussianBlur(Mat&,int w,int h,Mat& outputImg, int sigmaX, int sigmaY);
};