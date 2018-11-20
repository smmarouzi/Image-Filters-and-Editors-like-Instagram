 #include "..\include\GloServise.h"



GloService::GloService(bool debug_)
{
	debug = debug_;
}

int GloService::gamma(std::string inputPath, float gammaScale, std::string outputPath)
{
	GammaFilter gamma(inputPath, outputPath);
	gamma.debug = debug;
	return gamma.run(gammaScale); //A number between 0 and 1 for better brightness and contrast, 1 for the original image, more than 1 will be darker and darker
}

int GloService::sepia(std::string inputPath, float sepiaScale, std::string outputPath)
{
	Sepia sepia(inputPath, outputPath);
	sepia.debug = debug;
	return sepia.run(sepiaScale); //A number between 0 and 1. 0: original image, 1: full Sepia
}

int GloService::sepiatone(std::string inputPath, int tone, std::string outputPath)
{
	SepiaTone sepiatone(inputPath, outputPath);
	sepiatone.debug = debug;
	return sepiatone.run(tone); 
}

int GloService::hue_rotate(std::string inputPath, int degree, std::string outputPath)
{
	Hue_Rotate hue_rotate(inputPath, outputPath);
	hue_rotate.debug = debug;
	return hue_rotate.run(degree);
}

int GloService::saturate(std::string inputPath, float saturationScale, std::string outputPath)
{
	Saturation saturation(inputPath, outputPath);
	saturation.debug = debug;
	return saturation.run(saturationScale);
}

int GloService::hudson(std::string inputPath, float hudsonScale, std::string outputPath)
{
	Hudson hudson(inputPath, outputPath);
	hudson.debug = debug;
	return hudson.run(hudsonScale);
}

int GloService::ludwig(std::string inputPath, float ludwigScale, std::string outputPath)
{
	Ludwig ludwig(inputPath, outputPath);
	ludwig.debug = debug;
	return ludwig.run(ludwigScale);
}

int GloService::gray(std::string inputPath, float brightnessScale, std::string outputPath)
{
	Gray gray(inputPath, outputPath);
	gray.debug = debug;
	return gray.run(brightnessScale);
}

int GloService::bright(std::string inputPath, float brightnessScale, std::string outputPath)
{
	brightness bright(inputPath, outputPath);
	bright.debug = debug;
	return bright.run(brightnessScale);
}

int GloService::xproii(std::string inputPath, float xproiiScale, std::string outputPath)
{
	XProII xproii(inputPath, outputPath);
	xproii.debug = debug;
	return xproii.run(xproiiScale);
}

int GloService::contrast(std::string inputPath, float contrastScale, std::string outputPath)
{
	Contrast contrast(inputPath, outputPath);
	contrast.debug = debug;
	return contrast.run(contrastScale);
}

int GloService::juno(std::string inputPath, float junoScale, std::string outputPath)
{
	Juno juno(inputPath, outputPath);
	juno.debug = debug;
	return juno.run(junoScale);
}