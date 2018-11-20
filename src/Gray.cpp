#include "..\include\Gray.h"



Gray::Gray(std::string inputPath, std::string outputPath)
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


Gray::~Gray()
{
	std::string currOutputPath = outputFilePath + "/\\" + "gray" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int Gray::run(float brightnessScale)
{
	cv::cvtColor(input, result, cv::COLOR_RGB2GRAY);
	brightnessScale = round(brightnessScale * 255 - 255);
	result.convertTo(result, -1, 1, brightnessScale);

	if (debug)
		display();
	return 0;
}

void Gray::display()
{
	cv::imshow("Gray:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/**/
int main()
{
Gray gray("../GLoFilters/data/giftbag29.jpg", "../GLoFilters/result");
gray.run(1.3);
gray.display();

return 0;
}