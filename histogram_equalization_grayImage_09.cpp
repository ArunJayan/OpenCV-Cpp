//Histogram Equalization is defined as equalizingthe intensity of an image or flattering the intensity distribution curve.
//Histogram equalization is used to improve the contrast of an image.
//here we equalize the histogram of grayscale imgage
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img  = imread("sample.png",CV_LOAD_IMAGE_COLOR),gray;
	//load image
	if (!img.data)//if image not opened 
	{
		cout<<"Image can't be loaded"<<endl;
		return -1;
	}
	cvtColor(img,gray,CV_BGR2GRAY);//convert to grayscale
	Mat img_hist_eqlzd;
	equalizeHist(gray,img_hist_eqlzd);//equalize the histogram
	//first argument : input image array
	//second argument : output image array
	//create windows
	namedWindow("original",CV_WINDOW_AUTOSIZE);
	namedWindow("Histogram-Equalization",CV_WINDOW_AUTOSIZE);
	//show the images
	imshow("original",img);
	imshow("Histogram-Equalization",img_hist_eqlzd);
	waitKey(0);//wait for keypress
	return 0;
}