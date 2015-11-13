//Opencv supports for detecting mouse events .
//Mouse event includes mouse clicks and movement over attached opencv window.
//there is mouse_event_callback function in this program , that called every time ,
//when mouse events occur.
//that function giv coordinates of a mouse click
//it detect left,middle and right mouse clicks .

#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void mouse_event_callback(int event,int x,int y,int flags,void*)
{
	if(event==EVENT_LBUTTONDOWN)
	{
		cout<<"\nLeft button of mouse is clicked Position:("<<x<<","<<y<<")";
	}
	else if (event==EVENT_RBUTTONDOWN)
	{
		cout<<"\nRight button of mouse is clicked Position:("<<x<<","<<y<<")";
	}
	else if(event==EVENT_MBUTTONDOWN)
	{
		cout<<"\nMiddle button of mouse is clicked Position:("<<x<<","<<y<<")";

	}
	else if(event==EVENT_MOUSEMOVE)
	{
		cout<<"Mouse \nmove over the window Position:("<<x<<","<<y<<")";
	}
}
int main(int argc,char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	if(!img.data)
	{
		cout<<"Error in loading image";
		return -1;
	}
	namedWindow("MouseEvent",CV_WINDOW_AUTOSIZE);
	setMouseCallback("MouseEvent",mouse_event_callback,NULL);
	imshow("MouseEvent",img);
	waitKey(0);
	return 0;
}