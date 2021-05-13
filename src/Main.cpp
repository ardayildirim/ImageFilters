#include "Filterer.h"
#include <iostream>




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
	Filterer* filterer = new Filterer;

	std::string insertee;
	std::string result;
	int ind;

	Mat outputImg(image.size(),image.type());
	switch (c)
	{
	case '1':
		insertee = "BlackWhite";
		filterer -> BlackAndWhite(image, width, height);

		ind = imagename.find('.', 1);
		result = imagename.insert(ind, insertee);
		filterer->WriteToFile(image, result);
		cout << result << " written\n";
		break;
	case '2':
		insertee = "Highlighted";
		filterer -> BlackHighligtedWhite(image, width, height);

		ind = imagename.find('.', 1);
		result = imagename.insert(ind, insertee);
		filterer->WriteToFile(image, result);
		cout << result << " written\n";
		break;
	case '3':
		insertee = "Inverted";
		filterer -> InvertImage(image, width, height);

		ind = imagename.find('.', 1);
		result = imagename.insert(ind, insertee);
		filterer->WriteToFile(image, result);
		cout << result << " written\n";
		break;
	case '4':
		insertee = "Blurred";
		filterer -> GaussianBlur(image, width, height,outputImg, 10, 10);

		ind = imagename.find('.', 1);
		result = imagename.insert(ind, insertee);
		filterer->WriteToFile(outputImg, result);
		cout << result << " written\n";
		break;
	default:
		break;

	}
	

	
	return 0;

}