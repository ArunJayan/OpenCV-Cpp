#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
Mat img;
vector<Mat> channels;
//void function1(int slider1)
//{
	
//}
int main(int argc,const char** argv)
{
	Mat img(500,500,CV_8UC3,Scalar(0,0,0));
	if(!img.data)
	{
		cout<<"Image Can't be loaded"<<endl;
		return -1;
	}
	namedWindow("sample",1);
	vector<Mat> channels;
	split(img,channels);
	cout<<img[0][1];
	//int slider1 = 0;
	//createTrackbar("Blue","sample",&slider1,100,function1);
	//imshow
}