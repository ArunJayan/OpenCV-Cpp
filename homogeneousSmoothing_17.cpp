//Smoothing or Bluring 
//Main objective of smoothing is to reduce the noise
//Various metheods to smooth an image
//1.Homogeneous Smoothing
//2.Gaussian Smoothing
//3.MedianSmoothing
//4.Bilateral Smoothing

//Smoothing is done by sliding a window (kernel or filter) across the whole image and calculating each pixel a value based on the value of the kernel and the value of overlapping pixels of original image.
//[Number of rows and cols of kernel should be odd]
//[When size of kernel is getting larger , processing time also becomes larger]
//In this example we are going to use homogeneous smoothing
/*

simplest smoothing metheod . 
 It takes simply the average of the neighbourhood of a pixel and assign that value to itself.
5x5 kernel is used in homogeneous smoothing . This kernel is known as "Nomalizedbox filter"
		[	1	1	1	1	1 ]
		[	1	1	1	1	1 ]	
(1/25)*	[	1	1	1	1	1 ]
		[	1	1	1	1	1 ]
		[	1	1	1	1	1 ]
*/
#include <opemcv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	//create window
	namedWindow("img",CV_WINDOW_AUTOSIZE);
	namedWindow("smoothed img",CV_WINDOW_AUTOSIZE);
	//load image
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	imshow("img",img);//show the image
	if(!img.data)//if image is not loaded
	{
		cout<<"Image can't be loaded"<<endl;
	}
	Mat img1; //output
	char label[20];
	sprintf(label,"%d x %d",5,5);//label image
	blur(img,img1,Size(5,5));//bluring or smoothing
	putText(img1,label,Point(img.cols/4,img.rows/8), CV_FONT_HERSHEY_COMPLEX,1, Scalar(255, 255, 255));
	imshow("smoothed img",img1); //show the blured image.
	waitKey(0);//wait for keypress
	return 0;
}