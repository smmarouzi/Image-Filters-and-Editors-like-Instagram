#include "..\include\Hue_Rotate.h"
#include <math.h>

#define pi 3.14159265

Hue_Rotate::Hue_Rotate(std::string inputPath, std::string outputPath)
{
	inputFilePath = inputPath;
	outputFilePath = outputPath;
	input = cv::imread(inputPath);
	if (input.empty())
	{
		std::cerr << "Fail to open [" << inputPath << "]" << std::endl;
		system("pause");
		std::exit(1);
	}
}


Hue_Rotate::~Hue_Rotate()
{
	std::string currOutputPath = outputFilePath + "/\\" + "huerotate" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int Hue_Rotate::run(int degree)
{
	double cosdegree = cos(degree * pi/ 180);
	double sindegree = sin(degree * pi/ 180);

	cv::Mat huerotatematrix = (cv::Mat_<float>(3, 3) << (cosdegree + (1.0 - cosdegree) / 3.0), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree),
		((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), (cosdegree + (1.0 - cosdegree) / 3.0), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree),
		((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), (cosdegree + (1.0 - cosdegree) / 3.0));

	result = input.clone();

	for (int x = 0; x<input.cols; x++)
	{
		for (int y = 0; y<input.rows; y++)
		{
			// get pixel
			cv::Vec3b color = input.at<cv::Vec3b>(cv::Point(x, y));

			int b = color.val[0];
			int g = color.val[1];
			int r = color.val[2];

			int bx = cv::saturate_cast<uchar> (b*huerotatematrix.at<float>(0, 0) + g*huerotatematrix.at<float>(0, 1) + r*huerotatematrix.at<float>(0, 2));
			int gx = cv::saturate_cast<uchar> (b*huerotatematrix.at<float>(1, 0) + g*huerotatematrix.at<float>(1, 1) + r*huerotatematrix.at<float>(1, 2));
			int rx = cv::saturate_cast<uchar> (b*huerotatematrix.at<float>(2, 0) + g*huerotatematrix.at<float>(2, 1) + r*huerotatematrix.at<float>(2, 2));

			//set pixel
			result.at<cv::Vec3b>(cv::Point(x, y))[0] = bx;
			result.at<cv::Vec3b>(cv::Point(x, y))[1] = gx;
			result.at<cv::Vec3b>(cv::Point(x, y))[2] = rx;
		}
	}

	if (debug)
		display();

	return 0;

}

void Hue_Rotate::display()
{
	cv::imshow("HueRotate:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
int main()
{
	Hue_Rotate huerotate("../GLoFilters/data/tree.jpg", "../GLoFilters/result");
	huerotate.run(-180);
	huerotate.display();

	return 0;
}*/
