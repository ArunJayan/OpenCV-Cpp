//color_detection and object tracking example 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	VideoCapture cap(0); //capture video from camera
	if(!cap.isOpened())//if camera is not opened 
	{
		cout<<"Can not open the webcam"<<endl;
		return -1;
	}
	namedWindow("Control",CV_WINDOW_AUTOSIZE);//create window for placing trackbars
	int lowH = 0;
	int highH = 255;

	int lowS = 0;
	int highS = 255;

	int lowV = 0;
	int highV = 255;

	//creates trackbar in control window
	createTrackbar("LowH","Control",&lowH,255);
	createTrackbar("HighH","Control",&highH,255);

	createTrackbar("HighS","Control",&highS,255);
	createTrackbar("LowS","Control",&lowS,255);

	createTrackbar("HighV","Control",&highV,255);
	createTrackbar("LowV","Control",&lowV,255);

	while(true)
	{
		Mat frame;//frame 
		bool success = cap.read(frame);//read frame 
		if(!success)
		{
			cout<<"Can not read a frame"<<endl;
			break;
		}
		Mat img;
		cvtColor(frame,img,CV_BGR2HSV);//convert to hsv
		Mat thresholdImage;
		inRange(img,Scalar(lowH,lowS,lowV),Scalar(highH,highS,highV),thresholdImage);
		//threshold the image 
		erode(thresholdImage,thresholdImage,getStructuringElement(MORPH_ELLIPSE,Size(5,5)));
		dilate(thresholdImage,thresholdImage,getStructuringElement(MORPH_ELLIPSE,Size(5,5)));

		dilate(thresholdImage,thresholdImage,getStructuringElement(MORPH_ELLIPSE,Size(5,5)));
		erode(thresholdImage,thresholdImage,getStructuringElement(MORPH_ELLIPSE,Size(5,5)));
		
		imshow("threshold_image",thresholdImage);
		imshow("Frame",frame);
		if(waitKey(30)==27)
		{
			break;
		}

	}
	return 0;
	destroyAllWindows();
} 