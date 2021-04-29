#include "Filterer.h"


void Filterer::BlackAndWhite(Mat& img, int w, int h)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			uchar* pixel = PIXEL(img.data, w, j, i);
			int t = ((int)pixel[0] + pixel[1] + pixel[2])/3;
			pixel[0] = pixel[1] = pixel[2] = t;
		}
	}
}

void Filterer::BlackHighligtedWhite(Mat& img, int w, int h,double lim)
{
	long long sum = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			uchar* pixel = PIXEL(img.data, w, j, i);
			sum += pixel[0];
			sum += pixel[1];
			sum += pixel[2];
		}
	}
	if (lim >= 0)
	{
		;
	}
	else
	{
		long long average = (sum) / ((long long)w * h * 3);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				uchar* pixel = PIXEL(img.data, w, j, i);
				long t = ((long)pixel[0] + pixel[1] + pixel[2]) / 3;
				if (t >= average)
				{
					pixel[0] = pixel[1] = pixel[2] = 254;
				}
				else pixel[0] = pixel[1] = pixel[2] = 20;
			}
		}
	}
}

void Filterer::GaussianBlur(Mat& img, int w, int h,Mat& output, double val)
{
	cv::GaussianBlur(img, output, cv::Size(5, 5), val);
}

void Filterer::InvertImage(Mat& img, int w, int h)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			uchar* pixel = PIXEL(img.data, w, j, i);
			pixel[0] = 255 - pixel[0];
			pixel[1] = 255 - pixel[1];
			pixel[2] = 255 - pixel[2];
		}
	}
}