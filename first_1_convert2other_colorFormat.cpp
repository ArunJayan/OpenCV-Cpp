//HistogramEqualization_grayImage_08.cpp
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
	if(!img.data)
	{
		cout<<"Image Can not be loaded"<<endl;
		return -1;
	}
	cvtColor(img,gray,CV_BGR2GRAY);
	//cvtColor() can be ised convert image to other color formar like GRAYSCALE
	//first input
	namedWindow("gray",CV_WINDOW_AUTOSIZE);
	imshow("gray",gray);
	waitKey(0);
}