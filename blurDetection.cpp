#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/xphoto.hpp"

int main( int argc, char *argv[] ){
	
	if( argc != 2) {
		std::cout << "Proper usage is" << argv[0] << " <filename>\r\n";
		return -1;
	}

	cv::Mat image, grayscale, laplaced;

	image = cv::imread( argv[1] );

	//Convert to Grayscale
	cvtColor( image, grayscale, CV_BGR2GRAY );
	
	//Calculate the Laplacian for this 
	cv::Laplacian( grayscale, laplaced, CV_16S );

	//Variables for calculating the variance
	double sqMean, meanSq, variance;
	sqMean = meanSq = variance = 0.0;
	
	//Calculate one of the terms
	meanSq = cv::mean( laplaced )[0];
	meanSq = meanSq * meanSq;
	
	//Calculate Second term
	cv::pow( laplaced, 2., laplaced );
	sqMean = cv::mean( laplaced )[0];
	
	//Finish the variance calculation
	variance = sqMean - meanSq;

	std::cout << "Blur value is: " << variance << "\r\n";

	return 0;
}
