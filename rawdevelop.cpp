#include "libraw/libraw.h"
#include <iostream>

//std::string demosaicMethods[13] = {
//	"linear",
//	"VNG",
//	"PPG",
//	"AHD",
//	"DCB",
//	"mAHD",
//	"AFD",
//	"VCD",
//	"VCDAHD",
//	"LMMSE",
//	"AMaZE",
//	"DHT",
//	"mAHD.AP"
//};




int main( int argc, char *argv[] ){
	
	if(argc != 2) {
		std::cout << "Proper usage is as follows\r\n\t" << argv[0] << " <filename>\r\n";
		return -1;
	}


	//Create image processor
	LibRaw iProcessor;

	iProcessor.open_file(argv[1]);

	iProcessor.imgdata.params.output_tiff = 1;	
	iProcessor.imgdata.params.use_camera_wb = 1;
	iProcessor.imgdata.params.no_auto_bright = 1;		

	//Demosaic Method is AMaZE
	iProcessor.imgdata.params.user_qual = 10;
	
	std::cout << "Image Size: " << iProcessor.imgdata.sizes.width << " x " << iProcessor.imgdata.sizes.height << "\r\n";

	iProcessor.unpack();
	iProcessor.raw2image();
	
	iProcessor.dcraw_process();

	std::string newFilename(argv[1]);
	newFilename = newFilename.substr(0, newFilename.find_last_of("."));
	newFilename += ".tif";
	iProcessor.dcraw_ppm_tiff_writer(newFilename.c_str());
	
}
