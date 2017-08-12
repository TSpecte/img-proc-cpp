#include "utils.hpp"

int display(const Mat& in){
  if ( !in.data )
    {
        printf("No in data \n");
        return -1;
    }


    namedWindow("Display in", WINDOW_AUTOSIZE );
    imshow("Display in", in);

    waitKey(0);
    return 0;
}


int color2grey(const Mat& in, Mat& out){
	//assert...

	for (int i=0; i<in.rows; ++i){
        for (int j=0; j<in.cols; ++j){
        	uint32_t tmp = 
        			(uint32_t)(
        				0.2126 * in.at<Vec3b>(i,j)[0]
        		+ 		0.7152 * in.at<Vec3b>(i,j)[1]
        		+ 		0.0722 * in.at<Vec3b>(i,j)[2]
        		);
            out.at<uint8_t>(i,j) =  (uint8_t)tmp;
        }
    }
	return 0;
}

int convolve(Mat& in, const Mat& ker){
	return 0;
}


int info(const Mat& in){
    cout << "Image dim      = " << in.size()     << endl;
    cout << "Image depth    = " << in.type()     << endl;
    cout << "Image channels = " << in.channels() << endl;
    cout << "Image step     = " << in.step       << endl;
    cout << "Image total    = " << in.total()    << endl;

}