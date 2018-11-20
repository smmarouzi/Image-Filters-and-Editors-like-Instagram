#ifndef __SepiaTone_HPP__
#define __SepiaTone_HPP__

#include "common.h"

class SepiaTone
{
private:
	
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;

public:
	bool debug;

	SepiaTone(std::string inputPath, std::string outputPath);
	~SepiaTone();

	int run(int tone);
	void display();
};

#endif
