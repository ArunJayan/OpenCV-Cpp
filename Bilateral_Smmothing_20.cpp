//Bilateral Smmothing 
//THe most advanced filter to smooth image and reduce noise.
//Other Filters will smooth away the edges while removing noises . 
//drawback of this type is it takes longer time to process
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc,const char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	//load the image
	if(!img.data) //if image can not be loaded exit with -1
	{
		cout<<"Image can't be loaded"<<endl;
		return -1;
	}
	Mat img1;
	char text[30];
	sprintf(text,"%d x %d",5,5); //text to display in image 
	bilateralFilter(img,img1,5,5);
	/*
	*/
	putText(img1,text,Point(img.cols/4,img.rows/8),CV_FONT_HERSHY_COMPLEX,1,SCalar(255,255,255),2);
} 