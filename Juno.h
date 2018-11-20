#ifndef __Juno_HPP__
#define __Juno_HPP__

#include "common.h"

class Juno
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;
public:
	bool debug;

	Juno(std::string inputPath, std::string outputPath);
	~Juno();

	int run(float junoScale);// a number between 0 and 1
	void display();
};
#endif
