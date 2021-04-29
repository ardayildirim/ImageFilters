#include "Filterer.h"
#include <iostream>

#ifndef _PIXEL_
#define _PIXEL_

#define PIXEL(frame, W, x, y) (frame+(y)*3*(W)+(x)*3)

#endif


#define BLUR_LEVEL 12

int main()
{
	cout << "Enter a file name:";
	
	std::string imagename;
up:
	cin >> imagename;
	imagename = "images/" + imagename;
	Mat image = cv::imread(imagename);
	if (image.empty())
	{
		cout << "error\n";
		goto up;
	}

	int width = image.cols;
	int height = image.rows;

	char c;

	cout << "1- Black and White\n";
	cout << "2- White with black highlighting\n";
	cout << "3- Inverting the Image\n";
	cout << "4- Gaussian Blur\n";

	cin >> c;
	Filterer filterer;
	std::string insertee;
	Mat outputImg(image.size(),image.type());
	switch (c)
	{
	case '1':
		insertee = "BlackWhite";
		filterer.BlackAndWhite(image, width, height);
		break;
	case '2':
		insertee = "Highlighted";
		filterer.BlackHighligtedWhite(image, width, height);
		break;
	case '3':
		insertee = "Inverted";
		filterer.InvertImage(image, width, height);
		break;
	case '4':
		insertee = "Blurred";
		for (int i = 0; i < BLUR_LEVEL; i++)
		{
			filterer.GaussianBlur(image, width, height, outputImg);
			filterer.GaussianBlur(outputImg, width, height, image);
		}
		break;
	default:
		break;

	}
	

	int ind = imagename.find('.', 1);
	std::string result = imagename.insert(ind, insertee);

	cv::imwrite(result, image);
	cout << result << " written\n";
	return 0;

}