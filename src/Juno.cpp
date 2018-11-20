#include "..\include\Juno.h"



Juno::Juno(std::string inputPath, std::string outputPath)
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


Juno::~Juno()
{
	std::string currOutputPath = outputFilePath + "/\\" + "juno" + ".jpg";
	cv::imwrite(currOutputPath, result);
	std::cout << "Successfully written output image at " << currOutputPath << std::endl;
}

int Juno::run(float junoScale)
{
	float sepiaScale=0.35;//Between 0 and 1, 0:original image, 1:full sepia image
	float brightnessScale= 1 + junoScale*0.4;//brightnessScale is between 0 and 2, 0: black, 0-1: darker, 1: original image, 1-2: brighter, 2: white
	float contrastScale=1.15;//contrastScale a scale between 0 and 3. 0: black, 1: no effect,2: twice contrast
	float saturationScale=1.8;//saturationScale, 0:gray image, no saturation, 1: original image, 1-3: x times saturation

	result = input.clone();

	//Adjust saturation
	cv::Mat hsvInput;
	cv::cvtColor(result, hsvInput, cv::COLOR_BGR2HLS);

	result = hsvInput.clone();

	for (int x = 0; x < input.cols; x++)
	{
		for (int y = 0; y < input.rows; y++)
		{
			// get pixel
			cv::Vec3b hls = hsvInput.at<cv::Vec3b>(cv::Point(x, y));

			hls.val[2] = cv::saturate_cast<uchar>(hls.val[2] * saturationScale);
			result.at<cv::Vec3b>(cv::Point(x, y))[2] = hls.val[2];
		}
	}

	cv::cvtColor(result, result, cv::COLOR_HLS2BGR);

	// Adjust the bightness and contrast
	brightnessScale = round(brightnessScale * 255 - 255);
	result.convertTo(result, -1, contrastScale, brightnessScale);

	//Adjust sepia
	cv::Mat kern = (cv::Mat_<float>(3, 3) << (0.272 + 0.728 * (1 - sepiaScale)), (0.534 - 0.534 * (1 - sepiaScale)), (0.131 - 0.131 * (1 - sepiaScale)),
		(0.349 - 0.349 * (1 - sepiaScale)), (0.686 + 0.314 * (1 - sepiaScale)), (0.168 - 0.168 * (1 - sepiaScale)),
		(0.393 - 0.393 * (1 - sepiaScale)), (0.769 - 0.769 * (1 - sepiaScale)), (0.189 + 0.811 * (1 - sepiaScale)));

	cv::transform(result, result, kern);

	if (debug)
		display();
	return 0;
}

void Juno::display()
{
	cv::imshow("Juno:visuals", result);
	char key = cv::waitKey(0);
	cv::destroyAllWindows();
}

/*
int main()
{
	Juno juno("../GLoFilters/data/tree.jpg", "../GLoFilters/result");
	juno.run(0.7);
	juno.display();

	return 0;
}*/