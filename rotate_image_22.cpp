#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespacecv;

int main(int argc,char** argv)
{
	//Load image 
	Mat img = imread("sample.png")
	if(!img.data)//otherwise quit 
	{
		cout<<"Image can not be loaded."<<endl;
	}
	namedWindow("Rotate",CV_WINDOW_AUTOSIZE);
	//window created 
	int angle = 0;
	createTrackbar("Angle : ","Rotate",&angle,360);
	//trackbar to variying the angle 
	while(true)
	{
		Mat rotation = getRotationMatrix2D(Point(img.rows/2,img.cols/2),angle,1);
		//This function returns 2x3 affine transformation matrix for the 2D rotation.
		//Aurguments : 
		//			 Center : center of the rotation of the source img
		//			 Angle :  angle of rotation
		//			 Scale : scaling factor of image.
		Mat img_rotated;
		warpAffine(img,img_rotated,rotation,img.size());
		//applies affine transformation to an image
		//Arguments :
		//			 1st : source image
		//			 2nd : output image
	}

}