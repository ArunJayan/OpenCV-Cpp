//Smoothing or Bluring 
//Main objective of smoothing is to reduce the noise
//Various metheods to smooth an image
//1.Homogeneous Smoothing
//2.Gaussian Smoothing
//3.MedianSmoothing
//4.Bilateral Smoothing

//Smoothing is done by sliding a window (kernel or filter) across the whole image and calculating each pixel a value based on the value of the kernel and the value of overlapping pixels of original image.
//[Number of rows and cols of kernel should be odd]
//[When size of kernel is getting larger , processing time also becomes larger]
//In this example we are going to use homogeneous smoothing
/*

simplest smoothing metheod . 
 It takes simply the average of the neighbourhood of a pixel and assign that value to itself.
5x5 kernel is used in homogeneous smoothing . This kernel is known as "Nomalizedbox filter"
		[	1	1	1	1	1 ]
		[	1	1	1	1	1 ]	
(1/25)*	[	1	1	1	1	1 ]
		[	1	1	1	1	1 ]
		[	1	1	1	1	1 ]
*/
#include <opemcv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	//create window
	namedWindow("img",CV_WINDOW_AUTOSIZE);
	namedWindow("smoothed img",CV_WINDOW_AUTOSIZE);
	//load image
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	imshow("img",img);//show the image
}