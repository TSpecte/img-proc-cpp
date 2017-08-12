#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <opencv2/opencv.hpp>
#include "stdint.h"
#include <cmath>

#include "Image.hpp" 

using namespace cv;
using namespace std;

int display(const Mat& in);

int color2grey(const Mat& in, Mat& out);

int info(const Mat& in);

#endif
