#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat img,hsv; //image 
vector<Mat> channels; // vector to store channels
int main(int argc,const char** argv)
{
	img = imread("opencv_logo.png",CV_LOAD_IMAGE_COLOR);//load the image
	if(!img.data)
	{
		cout<<"Image can't be loaded";
	}
	cvtColor(img,hsv,CV_BGR2HSV); //convert tp HSV
	namedWindow("Splitting-Img",CV_WINDOW_AUTOSIZE);
	//creates a window 
	split(hsv,channels);
	//split RGB image into channels : R,G,B
	imshow("Splitting-Img",img);
	imshow("ch1",channels[0]);
	imshow("ch2",channels[1]);
	imshow("ch3",channels[2]);
	waitKey(0);
	return 0;
}