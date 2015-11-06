#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img(500,800,CV_8UC3,Scalar(0,255,190));
	//creates a empty image with a particular RGB value
	//first 2 parameter is img size
	//third parameter is type of image
	// CV_8UC3 --> 8bit unsigned integer with 3 channel
	// CV_8UC1 --> 8bit unsigned integer with single channel
	namedWindow("blankImage",CV_WINDOW_AUTOSIZE);//creates a window
	imshow("blankImage",img);//displays the image
	waitKey(0);//waits for keypress
	destroyWindow("blankImage");
}