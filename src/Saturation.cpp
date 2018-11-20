#include "..\include\Saturation.h"



Saturation::Saturation(std::string inputPath, std::string outputPath)
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


Saturation::~Saturation()
{
	std::string currOutputPath = outputFilePath + "/\\" + "saturation" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int Saturation::run(float saturationScale)
{
	cv::Mat hsvInput;
	cv::cvtColor(input, hsvInput, cv::COLOR_BGR2HLS);

	result = hsvInput.clone();

	for (int x = 0; x < input.cols; x++)
	{
		for (int y = 0; y < input.rows; y++)
		{
			// get pixel
			cv::Vec3b hls = hsvInput.at<cv::Vec3b>(cv::Point(x, y));

			hls.val[2] = cv::saturate_cast<uchar>(hls.val[2]*saturationScale);
			result.at<cv::Vec3b>(cv::Point(x, y))[2] = hls.val[2];
		}
	}

	cv::cvtColor(result, result, cv::COLOR_HLS2BGR);

	if (debug)
		display();
	return 0;
}

void Saturation::display()
{
	cv::imshow("Saturation:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
int main()
{
	Saturation saturation("../GLoFilters/data/tree.jpg", "../GLoFilters/result");
	saturation.run(0.7);
	saturation.display();

	return 0;
}*/