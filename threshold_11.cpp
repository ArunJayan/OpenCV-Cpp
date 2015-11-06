/*
thresholding is the simplest segmentation metheod.

There are 5 type of thresholding
0. Binary
1. Binary Inverted
2. Threshold Truncated
3. Threshold to zero
4. Threshold to zero inverted

Binary thresholding (0) : if the pixel image[x,y] is higher than the threshold value , then the new pixel intensity is set to MaxVal
					otherwise pixel are set to zero (image[x,y]<threshold value)
Binary inverted(1) : 	opposite of Binary thresholding . 
Threshold Trucate(2)  : if image[x,y]>threshold value then it is set to threshold
						otherwise image[x,y]
Threshold to zero (3): 	if image[x,y]<threshold value it is set zero
						otherwise image[x,y]
Threshold to zero inverted (4): if image[x,y]>threshold value , it set to 0
							otherwise image[x,y]
*/
//ref : http://docs.opencv.org/2.4/doc/tutorials/imgproc/threshold/threshold.html


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("apple.jpg",CV_LOAD_IMAGE_COLOR);
	//load the image
	Mat gray,binary_thresh,binary_inv,truncate_thresh,threshold2zero,threshold2zero_inv;
	cvtColor(img,gray,CV_BGR2GRAY);
	if(!img.data)
	{
		cout<<"Image Can't be loaded"<<endl;
		return -1;
	}
	//threshold()
	threshold(gray,binary_thresh,110,255,0); //binary thresholding 
	//first argument : source image
	//second argu 	 : output image
	//third argu 	 : threshold value
	//MaxVal 		 : The value used for binary thresholding operation
	//threshold type : One of the 5 thresholding operation
	threshold(gray,binary_inv,110,255,1);//binary inverted 
	threshold(gray,truncate_thresh,110,255,2);//truncate
	threshold(gray,threshold2zero,110,255,3);//threshold to zero
	threshold(gray,threshold2zero_inv,110,255,4);
	//windows
	namedWindow("original",CV_WINDOW_NORMAL);
	namedWindow("binar-threshold",CV_WINDOW_NORMAL);
	namedWindow("binary_inv",CV_WINDOW_NORMAL);
	namedWindow("truncate_thresh",CV_WINDOW_NORMAL);
	namedWindow("threshold2zero",CV_WINDOW_NORMAL);
	namedWindow("threshold2zero_inv",CV_WINDOW_NORMAL);

	imshow("original",img);
	imshow("binar-threshold",binary_thresh);
	imshow("binary_inv",binary_inv);
	imshow("truncate_thresh",truncate_thresh);
	imshow("threshold2zero",threshold2zero);
	imshow("threshold2zero_inv",threshold2zero_inv);
	waitKey(0);//wait  for keypress
	destroyAllWindows();
}