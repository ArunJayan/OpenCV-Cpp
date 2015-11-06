#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("cat.jpg",CV_LOAD_IMAGE_COLOR),imgout;
	namedWindow("filter",CV_WINDOW_AUTOSIZE);

	//dilate(img,img,Mat(),Point(-1, -1), 2, 1, 1);
	dilate(img,imgout,Mat(),Point(-1, -1), 2, 1, 1);
	imshow("filter1",img);
	imshow("filter",imgout);
	waitKey(0);
	return 0;
}