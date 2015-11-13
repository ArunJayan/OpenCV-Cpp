#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>
using namespace std;
using namespace cv;

Mat img;

void imTool(int event, int x, int y, int flags, void* param)
{
    char text[100];
    Mat img2, img3;

    img2 = img.clone();//copy img to img2 //img2 = img

    if (event == CV_EVENT_LBUTTONDOWN)//if left button clicked
    {
        Vec3b p = img2.at<Vec3b>(y,x);
        sprintf(text, "R=%d, G=%d, B=%d", p[2], p[1], p[0]);//text message that print R,G,B values
    }
    else if (event == CV_EVENT_RBUTTONDOWN)//if right button clicked
    {
        cvtColor(img, img3, CV_BGR2HSV);//convert to HSV and store that image in img3
        Vec3b p = img3.at<Vec3b>(y,x);
        sprintf(text, "H=%d, S=%d, V=%d", p[0], p[1], p[2]);//text message that print H,S,V values
    }
    else
        sprintf(text, "x=%d, y=%d", x, y);//otherwise print coodinates 
	cout<<text<<endl;
     putText(img2, text, Point(430,15), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(0,0,255));
    imshow("imtool", img2);
}

int main(int argc, char** argv)
{
    img = imread(argc == 2 ? argv[1] : "sample.png");//read the image
    if (img.empty())//if image is not loaded exit
        return -1;

    namedWindow("imtool");
    setMouseCallback("imtool", imTool, 0);//mouse callback function
    imshow("imtool", img);
    waitKey(0);

    return 0;
}
