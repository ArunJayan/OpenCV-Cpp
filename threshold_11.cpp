/*
thresholding is the simplest segmentation metheod.

There are 5 type of thresholding
1. Binary
2. Binary Inverted
3. Threshold Truncated
4. Threshold to zero
5. Threshold to zero inverted

*/
//ref : http://docs.opencv.org/2.4/doc/tutorials/imgproc/threshold/threshold.html


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("apple.jpg",CV_LOAD_IMAGE_COLOR);
	//load the image
	Mat gray,out;
	cvtColor(img,gray,CV_BGR2GRAY);
	if(!img.data)
	{
		cout<<"Image Can't be loaded"<<endl;
		return -1;
	}
	threshold(gray,out,90,255,1);
	namedWindow("original",CV_WINDOW_NORMAL);
	namedWindow("threshold",CV_WINDOW_NORMAL);
	imshow("original",img);
	imshow("threshold",out);
	waitKey(0);//wait  for keypress
}