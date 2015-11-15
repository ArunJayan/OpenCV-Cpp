//Common smoothing/Blurring metheod
//This is also used to reduce the noises of image . 
//Gaussian Kernel is slided across the image to produce the smoothed image

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	//loaded image
	if(!img.data)//image can't be loaded print message
	{
		cout<<"Image can't be loaded"<<endl;
		retun -1;
	}
	Mat img1,img2;
	char label[30];

	sprintf(label,"%d x %d",3,3);//label message
	GaussianBlur(img,img1,Size(3,3),0,0);//smooth image using Gaussian Blur
	/*
	1st argument : source image
	2nd argument : destination image
	3rd argument : Kernel size
	4th argument : sigmaX , standard deviation in x direction , here 0 is used . 
	5th argyment : sigmaY , standard deviation in y direction.
	*/
	putText(img1,label,Point(img.cols/4,img.rows/8),CV_FONT_HERSHEY_COMPLEX,1,Scalar(255,255,255),2);
	//put the text in the image

	sprintf(label,"%d x %d",7,7);
	GaussianBlur(img,img2,Size(7,7),0,0);//GaussianBlurring
	putText(img2,label,Point(img.cols/4,img.rows/8),CV_FONT_HERSHEY_COMPLEX,1,Scalar(255,255,255),2);

	imshow("GaussianBlur3x3",img1);
	imshow("OriginalImage",img);
	imshow("GaussianBlur7x7",img2);
	waitKey(0);
	return 0;
}
