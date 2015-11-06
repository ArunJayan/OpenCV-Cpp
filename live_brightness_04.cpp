#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat frame,dark,light;
	VideoCapture cap(0);
	if(!cap.isOpened())
	{
		cout<<"Check your webcam"<<endl;
	}
	namedWindow("frame",CV_LOAD_IMAGE_COLOR);
	namedWindow("dark",CV_LOAD_IMAGE_COLOR);
	namedWindow("light",CV_LOAD_IMAGE_COLOR);
	while(true)
	{
		cap.read(frame);
		dark = frame+Scalar(-90,-90,-90);
		light = frame+Scalar(90,90,90);
		imshow("frame",frame);
		imshow("dark",dark);
		imshow("light",light);

		if(waitKey(30)==27)
		{
			cout<<"Esc";
			break;
		}
	}
	return 0;
}