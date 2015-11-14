//This is also a common smoothing technique. 
//The input image is convolved with a Median kernel.
// Median filtering is widely used in edge detection algorithms because under certain conditions, it preserves edges while removing noise.
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	//image loaded

	if(!img.data)
	{
		cout<<"Image can't be loaded"<<endl;
		return -1;
	}

	Mat img1;//image named img1 
	char label[30];//label

	sprintf(label,"%d x %d",3,3); ///label1
	medianBlur(img,img1,3);//medianblurring using 3x3 kernel
	/*
	1st argument : source image
	2nd argument : destination 
	3rd argumnet : kernel size
	*/
	putText(img1,label,Point(img.cols/4,img.rows/8),CV_FONT_HERSHEY_COMPLEX,1,Scalar(255,255,255),2);
	//put the Text in image
	imshow("OriginalImage",img);//show the original image
	imshow("MedianBlurr",img1);//smoothed image using medianBlur()
	waitKey(0);
	return 0;

}