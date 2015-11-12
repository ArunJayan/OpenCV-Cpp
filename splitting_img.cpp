#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img; //image 
vector<Mat> channels; // vector to store channels
int main(int argc,const char** argv)
{
	img = imread("opencv_logo.png",CV_LOAD_IMAGE_COLOR);//load the image
	if(!img.data)
	{
		cout<<"Image can't be loaded";
	}

	namedWindow("Splitting-Img",CV_WINDOW_AUTOSIZE);
	//creates a window 
	split(img,channels);
	//split RGB image into channels : R,G,B
	imshow("Splitting-Img",img);
	imshow("B",channels[0]);
	imshow("G",channels[1]);
	imshow("R",channels[2]);
	waitKey(0);
	return 0;
}