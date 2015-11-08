#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat frame;
	VideoCapture cap(0);//set VideoCapture object
	namedWindow("Live",CV_WINDOW_AUTOSIZE);
	if(!cap.isOpened())//is web cam is connected
	{
		cout<<"Check your camera"<<endl;
		return -1;
	}
	while(true)
	{
		Mat out;
		bool success = cap.read(frame); //read each frame
		if(!success)
		{
			cout<<"Frames can't be readed"<<endl;
		}
		inRange(frame,Scalar(73,41,29),Scalar(65,38,18),out);
		imshow("Live",out);
		if(waitKey(30)==27)
		{
			break;
		}
	}
	
	return 0;
	destroyAllWindows();
	
}
//73 41 29
//65 38 18
