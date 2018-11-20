#include "..\include\Contrast.h"



Contrast::Contrast(std::string inputPath, std::string outputPath)
{
	inputFilePath = inputPath;
	outputFilePath = outputPath;
	input = cv::imread(inputPath);
	if (input.empty())
	{
		std::cerr << "Fail to open [" << inputPath << "]" << std::endl;
		system("pause");
		std::exit(1);
	}
}


Contrast::~Contrast()
{
	std::string currOutputPath = outputFilePath + "/\\" + "contrast" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int Contrast::run(float contrastScale)
{
	input.convertTo(result, -1, contrastScale, 0);
	if (debug)
		display();
	return 0;
}

void Contrast::display()
{
	cv::imshow("Contrast:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
int main()
{
	Contrast c("../GLoFilters/data/giftbag29.jpg", "../GLoFilters/result");
	c.run(2.5);
	c.display();

	return 0;
}*/