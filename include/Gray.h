#ifndef __Gray_HPP__
#define __Gray_HPP__

#include "common.h"

class Gray
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;
public:
	bool debug;

	Gray(std::string inputPath, std::string outputPath);
	~Gray();

	int run(float brightnessScale);//brightnessScale is between 0 and 2, 0: black, 0-1: darker, 1: original image, 1-2: brighter, 2: white
	void display();
};
#endif
