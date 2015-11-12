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

int threshold_value; // threshold value
int threshold_type = 0;	//threshold type (0-4)

const char* label = "Type : \n0. Binary\n1. Binary Inverted\n2. Threshold Truncated\n3. Threshold to zero\n4. Threshold to zero inverted";

void threshold_function(int,void*)
{
	threshold(gray,out,threshold_value,255,threshold_type);//thresholding the gray image
	imshow("Threshold_Trackbar",gray);//show the image

}
int main(int argc,const char* argv)
{
	
}
