#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat image(500,500,CV_8UC3,Scalar(0,0,0));//create image
Mat channel[3]; //channels 
int ch1 = 0;	//channel1 -tracker variable	
int ch2 = 0;	//channel2 -tracker vairiable
int ch3 = 0;	//channel3 -tracker variable

void track_functn(int,void*)
{
   channel[0]=ch1;	//changing valur of channel 1 or B
   channel[1]=ch2; //G channel
   channel[2]=ch3; //R channel
   merge(channel,3,image); //merging channels
   imshow("Trackerbar_example", image);	//showing img

}
int main( int argc, char** argv )
{
	split(image, channel);//split the image into channels
	namedWindow("Trackerbar_example",CV_WINDOW_AUTOSIZE);//creates a window.
	createTrackbar("B :","Trackerbar_example",&ch1,255,track_functn); //Trackbar for Blue
	createTrackbar("G :","Trackerbar_example",&ch2,255,track_functn); //Trackbar for Green
	createTrackbar("R :","Trackerbar_example",&ch3,255,track_functn); //Trackbar for Red
	track_functn(0,0);	//functioncall
	while(true)
	{
		int c = waitKey(10);//wait for Esc for exit
		if((char)c == 27)
			break;
	}
	
}
/*
int main( int argc, char** argv )
{
	
   split(image, channel);
   channel[0]=255;
   channel[2]=255;
   channel[1]=255;
   merge(channel,3,image);
   imshow("R+G", image);
   waitKey(0);//Wait for a keystroke in the window
    return 0;	
}
*/