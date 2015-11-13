//imtool
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;

void imtool(int event, int x, int y, int flags, void* param)
{
    char text[100];
    Mat img2, img3;

    img2 = img.clone();

    if (event == EVENT_LBUTTONDOWN)//if left button clicked
    {
        Vec3b p = img2.at<Vec3b>(y,x);
        sprintf(text, "R=%d, G=%d, B=%d", p[2], p[1], p[0]);//text message that print R,G,B values
    }
    else if (event == EVENT_RBUTTONDOWN)
    {
        cvtColor(img, img3, CV_BGR2HSV);
        Vec3b p = img3.at<Vec3b>(y,x);
        sprintf(text, "H=%d, S=%d, V=%d", p[0], p[1], p[2]);
    }
    else
    {

     	 sprintf(text, "x=%d, y=%d", x, y);
     	 //cout<<text;
    }
    cout<<text<<endl;
    putText(img2, text, Point(430,15), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(0,0,255));
    imshow("imtool", img2);
}

int main(int argc, char** argv)
{
    img = imread("sample.png");
    if (img.empty())
        return -1;

    namedWindow("imtool");
    setMouseCallback("imtool", imtool, 0);
    imshow("imtool", img);
    waitKey(0);

    return 0;
}