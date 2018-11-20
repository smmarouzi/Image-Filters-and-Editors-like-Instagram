#include "..\include\Hudson.h"
#include <math.h>

#define pi 3.14159265

Hudson::Hudson(std::string inputPath, std::string outputPath)
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


Hudson::~Hudson()
{
	std::string currOutputPath = outputFilePath + "/\\" + "hudson" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int Hudson::run(float hudsonScale)
{
	float sepiaScale = 0.25;//Between 0 and 1, 0:original image, 1:full sepia image
	float brightnessScale = 1 + hudsonScale*0.4;//brightnessScale is between 0 and 2, 0: black, 0-1: darker, 1: original image, 1-2: brighter, 2: white
	float contrastScale = 1.2;//contrastScale a scale between 0 and 3. 0: black, 1: no effect,2: twice contrast
	float saturationScale = 1.05;//saturationScale, 0:gray image, no saturation, 1: original image, 1-3: x times saturation
	int degree=-15;//degree (any range)

	result = input.clone();

	//Adjust hue rotate
	double cosdegree = cos(degree * pi / 180);
	double sindegree = sin(degree * pi / 180);

	cv::Mat huerotatematrix = (cv::Mat_<float>(3, 3) << (cosdegree + (1.0 - cosdegree) / 3.0), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree),
		((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), (cosdegree + (1.0 - cosdegree) / 3.0), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree),
		((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), ((1.0 / 3.0)*(1.0 - cosdegree) - sqrt(1.0 / 3.0)*sindegree), (cosdegree + (1.0 - cosdegree) / 3.0));

	for (int x = 0; x<result.cols; x++)
	{
		for (int y = 0; y<result.rows; y++)
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

	//Adjust saturation
	cv::Mat hsvInput;
	cv::cvtColor(result, hsvInput, cv::COLOR_BGR2HLS);

	result = hsvInput.clone();

	for (int x = 0; x < input.cols; x++)
	{
		for (int y = 0; y < input.rows; y++)
		{
			// get pixel
			cv::Vec3b hls = hsvInput.at<cv::Vec3b>(cv::Point(x, y));

			hls.val[2] = cv::saturate_cast<uchar>(hls.val[2] * saturationScale);
			result.at<cv::Vec3b>(cv::Point(x, y))[2] = hls.val[2];
		}
	}
	cv::cvtColor(result, result, cv::COLOR_HLS2BGR);

	//Adjust sepia
	cv::Mat kern = (cv::Mat_<float>(3, 3) << (0.272 + 0.728 * (1 - sepiaScale)), (0.534 - 0.534 * (1 - sepiaScale)), (0.131 - 0.131 * (1 - sepiaScale)),
		(0.349 - 0.349 * (1 - sepiaScale)), (0.686 + 0.314 * (1 - sepiaScale)), (0.168 - 0.168 * (1 - sepiaScale)),
		(0.393 - 0.393 * (1 - sepiaScale)), (0.769 - 0.769 * (1 - sepiaScale)), (0.189 + 0.811 * (1 - sepiaScale)));

	cv::transform(result, result, kern);

	// Adjust the bightness and contrast
	brightnessScale = round(brightnessScale * 255 - 255);
	result.convertTo(result, -1, contrastScale, brightnessScale);

	if (debug)
		display();
	return 0;
}

void Hudson::display()
{
	cv::imshow("Hudson:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();

}/*
int main()
{
	Hudson hudson("../GLoFilters/data/tree.jpg", "../GLoFilters/result");
	hudson.run(0.3);
	hudson.display();

	return 0;
}*/