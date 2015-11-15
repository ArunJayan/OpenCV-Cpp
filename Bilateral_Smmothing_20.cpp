//Bilateral Smmothing 
//THe most advanced filter to smooth image and reduce noise.
//Other Filters will smooth away the edges while removing noises . 
//drawback of this type is it takes longer time to process
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc,const char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	
} 