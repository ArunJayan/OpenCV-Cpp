#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
//included the lib.
using namespace std;
using namespace cv;
/*
There are 5 type of thresholding
0. Binary
1. Binary Inverted
2. Threshold Truncated
3. Threshold to zero
4. Threshold to zero inverted
*/
Mat img,gray,out; //Mat variable to hold img array

int threshold_value = 0; // threshold value
int threshold_type = 0;	//threshold type (0-4)

const char* label = "Threshold Type (0-4) :";//label

void threshold_function(int,void*)
{
	threshold(gray,out,threshold_value,255,threshold_type);//thresholding the gray image
	imshow("Threshold_Trackbar",out);//show the image

}
int main(int argc,const char** argv)
{
	img = imread("sample.png",CV_LOAD_IMAGE_COLOR);//read the source image.
	cvtColor(img,gray,CV_BGR2GRAY);//convert the source img to grayscale . 
	namedWindow("Threshold_Trackbar",CV_WINDOW_AUTOSIZE);//creates a window.
	createTrackbar("ThresholdValue :","Threshold_Trackbar",&threshold_value,255,threshold_function);
	//in the above step we create a trackbar to variy threshold value
	createTrackbar(label,"Threshold_Trackbar",&threshold_type,4,threshold_function);
	//creates another trackbar to variying threshold type
	threshold_function(0,0);
	while(true)
	{
		if((char)waitKey(10)==27) // wait for Esc to press
			break;
	}
	return 0;
	destroyWindow("Threshold_Trackbar");

}
