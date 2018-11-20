#ifndef __XProII_HPP__
#define __XProII_HPP__

#include "common.h"

class XProII
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;

public:
	bool debug;

	XProII(std::string inputPath, std::string outputPath);
	~XProII();

	int run(float xproiiScale);// a number between 0 and 1
	void display();
};

#endif