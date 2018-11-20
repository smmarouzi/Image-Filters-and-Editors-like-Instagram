#ifndef __Ludwig_HPP__
#define __Ludwig_HPP__

#include "common.h"

class Ludwig
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;
public:
	bool debug;

	Ludwig(std::string inputPath, std::string outputPath);
	~Ludwig();

	int run(float ludwigScale);// a number between 0 and 1
	void display();
};

#endif