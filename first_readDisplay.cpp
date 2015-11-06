
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img;//Mat datastructure stores image
	img = imread("cat.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	//using imread() we can read image
	//first argument is name of the image to be loaded
	// second argument is the flag :
	//						CV_LOAD_IMAGE_COLOR
	//						CV_LOAD_IMAGE_UNCHANGED
	//						CV_LOAD_IMAGE_GRAYSCALE
	//						CV_LOAD_IMAGE_ANYCOLOR
	//						CV_LOAD_IMAGE_ANYDEPTH

	if(!img.data) //if image is not loaded
	{
		cout<<"Image can not be loaded"<<endl;
	}
	else
	{
		cout<<"Image loaded successfully"<<endl;
	}
//cout<<img;  //display binary image
	namedWindow("cat",CV_WINDOW_AUTOSIZE);
	//create a window for showing the image
	// first parameter is the name of the window
	// second is the flag :
	//				CV_WINDOW_AUTOSIZE
	//				CV_WINDOW_NORMAL
	imshow("cat",img);
	//display the image in window
	waitKey(0);
	//waitKey() for  a keypress for certain time
	destroyWindow("cat");
	return 0;
}