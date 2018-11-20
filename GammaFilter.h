#ifndef __GammaFilter__
#define __GammaFilter__

#include "common.h"

class GammaFilter
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;

public:
	bool debug;

	GammaFilter(std::string inputPath, std::string outputPath);
	~GammaFilter();

	int run(float gammaScale); //A number between 0 and 1 for better brightness and contrast, 1 for the original image, more than 1 will be darker and darker
	void display();
};

#endif

