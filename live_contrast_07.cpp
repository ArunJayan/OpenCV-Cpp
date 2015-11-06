//contrast_06.cpp
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	VideoCapture cap(0);
	Mat img,imgL,imgH;
	if(!cap.isOpened())
	{
		cout<<"check ur cam"<<endl;
		return -1;
	}
namedWindow("Original-image",CV_WINDOW_AUTOSIZE);
namedWindow("High-Contrast",CV_WINDOW_AUTOSIZE);
namedWindow("Low-Contrast",CV_WINDOW_AUTOSIZE);
while(true)
{
	bool success = cap.read(img);//read each frame
	if(!success)
	{
		cout<<"Can not read the frame"<<endl;
		break;
	}
	img.convertTo(imgH,-1,2,0);//convert to high contrast
	img.convertTo(imgL,-1,.4,0);//convert to low contrast
	imshow("Original-image",img);
	imshow("High-Contrast",imgH);
	imshow("Low-Contrast",imgL);
	if(waitKey(30)==27){
		break;
	}
	//waits for keypress
}
	destroyAllWindows();
	return 0;
}