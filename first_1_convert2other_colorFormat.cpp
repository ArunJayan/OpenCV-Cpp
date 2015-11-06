#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	//load the image
	Mat gray;
	if(!img.data)//if imageis not loaded
	{
		cout<<"Image Can not be loaded"<<endl;
		return -1;
	}
	cvtColor(img,gray,CV_BGR2GRAY);
	//cvtColor() can be ised convert image to other color formar like GRAYSCALE
	//first argument input is source imag
	//second is target image
	//third is target color format 
	//available color format are :
	// 				CV_BGR2GRAY
	//				CV_BGR2HSV	
	//				CV_HSV2BGR
	//				CV_GRAY2BGR
	//there is fourth parameter , if we have to change no of channels
	namedWindow("gray",CV_WINDOW_AUTOSIZE);//creates a window
	imshow("gray",gray);//show the image
	waitKey(0);//wait for any keypress
}