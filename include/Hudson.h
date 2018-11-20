#ifndef __Hudson_HPP__
#define __Hudson_HPP__

#include "common.h"

class Hudson
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;
public:
	bool debug;

	Hudson(std::string inputPath, std::string outputPath);
	~Hudson();

	int run(float hudsonScale);// a number between 0 and 1
	void display();
};

#endif