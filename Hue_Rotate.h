#ifndef __Hue_Rotate_HPP__
#define __Hue_Rotate_HPP__

#include "common.h"

class Hue_Rotate
{
private:
	cv::Mat input;

	std::string inputFilePath;
	std::string outputFilePath;

	cv::Mat result;

public:
	bool debug;

	Hue_Rotate(std::string inputPath, std::string outputPath);
	~Hue_Rotate();

	int run(int degree);//degree (any range, positive or negetive)
	void display();
};

#endif