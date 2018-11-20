#ifndef __brightness_HPP__
#define __brightness_HPP__

#include "common.h"

class brightness
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;
public:
	bool debug;

	brightness(std::string inputPath, std::string outputPath);
	~brightness();

	int run(float brightnessScale);//brightnessScale is between 0 and 2, 0: black, 0-1: darker, 1: original image, 1-2: brighter, 2: white
	void display();
};
#endif

