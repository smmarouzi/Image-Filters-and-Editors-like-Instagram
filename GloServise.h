#ifndef __GLOSERVICE_HPP__
#define __GLOSERVICE_HPP__

#include "GammaFilter.h"
#include "Sepia.h"
#include "SepiaTone.h"
#include "Hue_Rotate.h"
#include "Saturation.h"
#include "brightness.h"
#include "Contrast.h"
#include "Hudson.h"
#include "Juno.h"
#include "Ludwig.h"
#include "XProII.h"
#include "Gray.h"

class GloService
{
public:
	bool debug;
	GloService(bool debug_ = false);
	int gamma(std::string inputPath, float gammaScale, std::string outputPath);
	int sepia(std::string inputPath, float sepiaScale, std::string outputPath);
	int sepiatone(std::string inputPath, int tone, std::string outputPath);
	int hue_rotate(std::string inputPath, int degree, std::string outputPath);
	int saturate(std::string inputPath, float saturationScale, std::string outputPath);
	int bright(std::string inputPath, float brightnessScale, std::string outputPath);
	int contrast(std::string inputPath, float contrastScale, std::string outputPath);
	int gray(std::string inputPath, float brightnessScale,  std::string outputPath);
	int juno(std::string inputPath, float junoScale, std::string outputPath);
	int hudson(std::string inputPath, float hudsonScale, std::string outputPath);
	int ludwig(std::string inputPath, float ludwigScale, std::string outputPath);
	int xproii(std::string inputPath, float xproiiScale, std::string outputPath);
};

#endif

