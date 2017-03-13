#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/xphoto.hpp"

int main( int argc, char *argv[] ){
	
	if( argc < 3) {
		std::cout << "Proper usage is" << argv[0] << " <filename1> ... <filenameN>\r\n";
		return -1;
	}
	
	std::vector<cv::Mat> aFrames;

	cv::Mat stackedFrames;

	for( int i = 1; i < argc; i++){
		
		//Load image
		aFrames.push_back( cv::imread( argv[i]) );
		
		if(i != 1){
		
			//Calculate image weights
			double beta = 1.0 / i;
			double alpha = 1.0 - beta;
			
			//Now stack them
			if(i < 2) continue;
			else if(i == 2) 
				addWeighted(	aFrames[0], alpha, 	//Frame and weight
						aFrames[1], beta, 	//Frame and weight
						0.0, 			//Gamma
						stackedFrames,		//Destination
						-1);			//dtype
			else
				addWeighted(	stackedFrames, alpha,
						aFrames[i-1], beta,
						0.0,
						stackedFrames,
						-1);
		}
			
	}


	std::string newname = argv[1];
	newname = newname.substr(0, newname.find_last_of("/") + 1);
	newname += "stackedImage.tif";

	cv::imwrite(newname, stackedFrames);

}
