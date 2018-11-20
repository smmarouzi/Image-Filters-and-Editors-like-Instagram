#ifndef SATURATION_HPP
#define SATURATION_HPP

#include "common.h"

class Saturation
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;

public:
	bool debug;

	Saturation(std::string inputPath, std::string outputPath);
	~Saturation();

	int run(float saturationScale);//saturationScale, 0:gray image, no saturation, 1: original image, 1-3: x times saturation
	void display();

};

#endif //SATURATION_HPP