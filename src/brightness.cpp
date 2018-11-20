#include "..\include\brightness.h"

brightness::brightness(std::string inputPath, std::string outputPath)
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


brightness::~brightness()
{
	std::string currOutputPath = outputFilePath + "/\\" + "brightness" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int brightness::run(float brightnessScale)
{
	brightnessScale = round(brightnessScale * 255 - 255);
	input.convertTo(result, -1, 1, brightnessScale);
	if (debug)
		display();
	return 0;
}

void brightness::display()
{
	cv::imshow("Brightness:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
int main()
{
	brightness c("../GLoFilters/data/tree.jpg", "../GLoFilters/result");
	c.run(1.25);
	c.display();

return 0;
}*/
