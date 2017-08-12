#include <stdio.h>
#include <cassert>
#include <opencv2/opencv.hpp>

#include "Image.hpp"
#include "utils.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );
    info(image);

    Mat imout = Mat::zeros(image.rows, image.cols, CV_8U);
    //info(imout);

    color2grey(image, imout);


    //************* CONVERSION FROM OPENCV ***********************
    Image<uint8_t> im2(image.rows, image.cols, 1);

    for(int i=0; i<image.rows; ++i)
        for(int j=0; j<image.cols; ++j)
            im2[i*image.cols + j] = imout.at<uint8_t>(i,j);

    //************************************************************
    //                       PROCESSING
    //************************************************************

    im2 /= 2;

    //*************** CONVERSION TO OPENCV ***********************
    for(int i=0; i<image.rows; ++i)
        for(int j=0; j<image.cols; ++j)
            imout.at<uint8_t>(i,j) = im2[i*image.cols + j];

    display(imout);

    return 0;
}