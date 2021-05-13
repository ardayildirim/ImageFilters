#include "Filterer.h"


void Filterer::WriteToFile(const Mat& img, const std::string& fileName)
{
	cv::imwrite(fileName, img);
}

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

void Filterer::GaussianBlur(Mat& img, int w, int h,Mat& output, int sigmaX, int sigmaY)
{
	int** numOfPixels = new int* [h];
	vec3** intOuts = new vec3* [h];
	for (int i = 0; i < h; i++)
	{
		numOfPixels[i] = new int[w];
		intOuts[i] = new vec3[w];
		for (int j = 0; j < w; j++)
		{
			numOfPixels[i][j] = 0;
			intOuts[i][j] = vec3(0, 0, 0);
		}
	}


	for (int i = 0; i < h; i++)
	{
		cout << "i: " << i << "\n";
		for (int j = 0; j < w; j++)
		{
			for (int y = i - sigmaY; y <= i + sigmaY; y++)
			{
				for (int x = j - sigmaX; x <= j + sigmaX; x++)
				{
					if (IN(x, y, w, h))
					{
						uchar* u = PIXEL(img.data, w, x, y);
						intOuts[i][j] = intOuts[i][j] +  vec3(u[0], u[1], u[2]);
						numOfPixels[i][j]++;
					}
				}
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			uchar* u = PIXEL(output.data, w, j, i);
			u[0] = intOuts[i][j][0] / numOfPixels[i][j];
			u[1] = intOuts[i][j][1] / numOfPixels[i][j];
			u[2] = intOuts[i][j][2] / numOfPixels[i][j];
		}
	}
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