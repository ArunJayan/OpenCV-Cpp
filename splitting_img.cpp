#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img; //image 
int main(int argc,const char** argv)
{
	img = imread("opencv_logo.png",CV_LOAD_IMAGE_COLOR);//load the image
	if(!img.data)
	{
		cout<<"Image can't be loaded";
	}

	return 0;
}