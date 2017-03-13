#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/xphoto.hpp"

int main( int argc, char *argv[] ){
	
	if( argc != 2) {
		std::cout << "Proper usage is" << argv[0] << " <filename>\r\n";
		return -1;
	}
	
	cv::Mat frame, ycrcb;
	cv::Mat eqFrame;
	
	frame = cv::imread( argv[1]);
	
	//convert to ycv
	cvtColor(frame, ycrcb, CV_BGR2YCrCb);	
	
	//split
	std::vector<cv::Mat> channels;
	split(ycrcb, channels);
	
	cv::equalizeHist(channels[0], channels[0]);

	merge(channels, ycrcb);
	
	cvtColor(ycrcb, eqFrame, CV_YCrCb2BGR);

	std::string newname = argv[1];
	newname = newname.substr(0, newname.find_last_of("/") + 1);
	newname += "equalizedImage.tif";

	cv::imwrite(newname, eqFrame);

}
