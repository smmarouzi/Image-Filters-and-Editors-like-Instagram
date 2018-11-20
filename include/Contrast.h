#ifndef __Contrast_HPP__
#define __Contrast_HPP__

#include "common.h"

class Contrast
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;
public:
	bool debug;

	Contrast(std::string inputPath, std::string outputPath);
	~Contrast();

	int run(float contrastScale);//contrastScale a scale between 0 and 3. 0: black, 1: no effect,2: twice contrast
	void display();
};
#endif
