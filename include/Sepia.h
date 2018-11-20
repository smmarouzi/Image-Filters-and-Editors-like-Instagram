#ifndef __Sepia_HPP__
#define __Sepia_HPP__

#include "common.h"

class Sepia
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;

public:
	bool debug;

	Sepia(std::string inputPath, std::string outputPath);
	~Sepia();

	int run(float sepiaScale);//Between 0 and 1, 0:original image, 1:full sepia image
	void display();
};

#endif

