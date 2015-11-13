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
	if(event==EVENT_LBUTTONDOWN)//if left button clicked
	{
		cout<<"\nLeft button of mouse is clicked Position:("<<x<<","<<y<<")";
	}
	else if (event==EVENT_RBUTTONDOWN)//if right button clicked
	{
		cout<<"\nRight button of mouse is clicked Position:("<<x<<","<<y<<")";
	}
	else if(event==EVENT_MBUTTONDOWN)//if middle button clicked
	{
		cout<<"\nMiddle button of mouse is clicked Position:("<<x<<","<<y<<")";

	}
	else if(event==EVENT_MOUSEMOVE)//if mouse moved
	{
		cout<<"Mouse \nmove over the window Position:("<<x<<","<<y<<")";
	}
}
int main(int argc,char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	//load a image
	if(!img.data)//if img can't be loaded exit with -1;
	{
		cout<<"Error in loading image";
		return -1;
	}
	namedWindow("MouseEvent",CV_WINDOW_AUTOSIZE);
	//creates a window named "MouseEvent"
	setMouseCallback("MouseEvent",mouse_event_callback,NULL);
	//set the callback function for any mouse event
	imshow("MouseEvent",img);
	//show the image
	waitKey(0);
	//wait for any keypress
	return 0;
}