//contrast_06.cpp
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat sample = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	//image loaded as sample
	if(!sample.data)
	{
		cout<<"Image can't be loaded"<<endl;
		return -1;
	}
	Mat img1,img2;
	sample.convertTo(img1,-1,2,0);
	// convertTo() functn covert img to annother format
	// m[i,j] = alpha*m[i,j]+beta
	// first parameter : output img (array)
	// second parameter->  Depth of output img like CV_8U,CV_32S,CV_64F,-1
	// we don't have to change the depth so we put -1
	// third parameter : alpha , multiplication factor , every pixel is multiplied by this value
	// fouth parameter : beta , this value added to every pixels
	// equation : m[i,j] = alpha*m[i,j]+betas
	// contrastw will increase when we multiplied by a no which is grater than 1
	// so above statement we increased contrast
	// and also we can decrease it by multiplying by no,less than one
	sample.convertTo(img2,-1,.5,0);
	//output=img2,type=NOne(becoz -1),alpha=.5,beta=0
	namedWindow("Original-image",CV_WINDOW_AUTOSIZE);
	namedWindow("High-Contrast",CV_WINDOW_AUTOSIZE);
	namedWindow("Low-Contrast",CV_WINDOW_AUTOSIZE);
	//above step we create 3 window
	imshow("Original-image",sample);
	imshow("High-Contrast",img1);
	imshow("Low-Contrast",img2);
	waitKey(0);
	//waits for keypress
	destroyAllWindows();
	return 0;
}