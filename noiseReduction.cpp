#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/xphoto.hpp"

int main( int argc, char *argv[] ){
	
	if( argc <= 2) {
		std::cout << "Proper usage is" << argv[0] << " <filename>\r\n";
		return -1;
	}

	cv::Mat noiseFreeFrame;
	
	//Single image denoising
	if(argc == 2){
		
		cv::Mat frame;

	} else { //Multi image denoise
		
		std::vector<cv::Mat> frames;
		
		for(int i = 1; i < argc; i++){
			frames.push_back( cv::imread(argv[i]) );	
		}
		
		fastNlMeansDenoisingColoredMulti(	frames,
							noiseFreeFrame,
							argc/2,
							argc-3,
							7,
							21);
	}
	
	std::string newname = argv[1];
	newname = newname.substr(0, newname.find_last_of("/") + 1);
	newname += "denoisedImage.tif";

	cv::imwrite(newname, noiseFreeFrame);

}
