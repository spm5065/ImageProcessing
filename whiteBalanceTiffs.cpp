#include <iostream>
#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>
#include "opencv2/xphoto.hpp"

int main( int argc, char *argv[] ){
	
	if( argc != 2) {
		std::cout << "Proper usage is" << argv[0] << " <filename>\r\n";
		return -1;
	}
	
	cv::Mat frame;
	frame = cv::imread( argv[1] );
	
	//cv::namedWindow( "", cv::WINDOW_AUTOSIZE);
	//cv::imshow( "Before Image", frame);

	//cv::waitKey(0);

	cv::Ptr<cv::xphoto::WhiteBalancer> wb;
	wb = cv::xphoto::createSimpleWB();
	wb->balanceWhite(frame, frame);

	std::string newname = argv[1];
	newname = newname.substr(0, newname.length() - 4) + "_wb" + ".tif"; 

	cv::imwrite(newname, frame);

	//cv::waitKey(0);
}
