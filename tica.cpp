#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Rect roi(440,280,200,200);
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR),out;
	Mat crop = img(roi);
	inRange(img,Scalar(31,54,49),Scalar(41,109,84),out);
	imshow("crop",crop);
	imshow("img",img);
	imshow("inRange",out);
	waitKey(0);
	return 0;
}