#include "..\include\GammaFilter.h"



GammaFilter::GammaFilter(std::string inputPath, std::string outputPath)
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


GammaFilter::~GammaFilter()
{
	std::string currOutputPath = outputFilePath + "/\\" + "gamma" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int GammaFilter::run(float gammaScale)
{
	CV_Assert(gammaScale >= 0);

	cv::Mat lookUpTable(1, 256, CV_8U);
	uchar* p = lookUpTable.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, gammaScale) * 255.0);
	result = input.clone();
	cv::LUT(input, lookUpTable, result);

	if (debug)
		display();

	return 0;
}

void GammaFilter::display()
{
	cv::imshow("GammaFilter:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
int main()
{
	GammaFilter gammafilter("../GLoFilters/data/giftbag29.jpg", "../GLoFilters/result");
	gammafilter.run(0.5);
	gammafilter.display();

	return 0;
}*/