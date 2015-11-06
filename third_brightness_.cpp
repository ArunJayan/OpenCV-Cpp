#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc,const char** argv)
{
	Mat image = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	if(!image.data)
	{
		cout<<"Image can't be loaded"<<endl;
	}
	Mat bright = image+Scalar(75,75,75);
	Mat dark = image+Scalar(-75,-75,-75);
	namedWindow("Bright");
	namedWindow("Original");
	namedWindow("dark");
	imshow("Bright",bright);
	imshow("dark",dark);
	imshow("Original",image);
	waitKey(0);
	return 0;

}