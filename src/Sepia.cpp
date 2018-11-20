#include "..\include\Sepia.h"


Sepia::Sepia(std::string inputPath, std::string outputPath)
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


Sepia::~Sepia()
{
	std::string currOutputPath = outputFilePath + "/\\" + "sepia" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int Sepia::run(float sepiaScale)
{
	result = input.clone();


	cv::Mat kern = (cv::Mat_<float>(3, 3) << (0.272 + 0.728 * (1 - sepiaScale)), (0.534 - 0.534 * (1 - sepiaScale)), (0.131 - 0.131 * (1 - sepiaScale)),
		(0.349 - 0.349 * (1 - sepiaScale)), (0.686 + 0.314 * (1 - sepiaScale)), (0.168 - 0.168 * (1 - sepiaScale)),
		(0.393 - 0.393 * (1 - sepiaScale)), (0.769 - 0.769 * (1 - sepiaScale)), (0.189 + 0.811 * (1 - sepiaScale)));

	cv::transform(input, result, kern);

	if (debug)
		display();

	return 0;
}

void Sepia::display()
{
	cv::imshow("Sepia:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
int main()
{
	Sepia sepia("../GLoFilters/data/tree.jpg", "../GLoFilters/result");
	sepia.run(0.5);
	sepia.display();

	return 0;
}*/
