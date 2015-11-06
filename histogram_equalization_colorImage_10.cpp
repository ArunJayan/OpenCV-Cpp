//histogram equalization of color image
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	//load image
	if(!img.data)
	{
		cout<<"Image Can't be loaded"<<endl;
		return -1;
	}

	vector<Mat> channels;
	Mat img_hist_equal;
	cvtColor(img,img_hist_equal,CV_BGR2YCrCb);
	//convert RGB --> YCrCb
	/*
	Here we have to equalize the histogram of intensity component only.
	But we can't perform on RGB becoz its three channels contains only color components not intensity component
	So we convert RGB-->YCrCb 
	YCrCb's frist channel (first component represents intensity )
	so we equalize that intensity component using equalizeHist()
	and we merge this modified channel with other channel
	*/
	split(img_hist_equal,channels);//here we split images to channels
	//functionsplits each channel of image into vector
	//first argument source image
	//second is a vector that stores each channels
	//imshow("channels",channels[2]);
	equalizeHist(channels[0],channels[0]);//equalize histogram on the firstchannel
	merge(channels,img_hist_equal);//merge 3 channels including themodified channel into  one image
	//first argument is vector that holds different channels
	//next argument is ouput img.
	cvtColor(img_hist_equal,img_hist_equal,CV_YCrCb2BGR);
	//convert YCrCb --> RGB
	namedWindow("Original",CV_WINDOW_AUTOSIZE);
	namedWindow("histogram",CV_WINDOW_AUTOSIZE);
	//show the image
	imshow("Original",img);
	imshow("histogram",img_hist_equal);
	waitKey(0);
}