#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("sample.png",CV_LOAD_IMAGE_COLOR);
	if(!img.data){
		cout<<"Image can not be loaded"<<endl;
		return -1;
	}
	//create a window
	namedWindow("Tracker",CV_WINDOW_AUTOSIZE);

	int slider1 = 50;
	createTrackbar("brightness","Tracker",&slider1,200);
	

	int slider2 = 50;
	createTrackbar("contrast","Tracker",&slider2,200);

	while(true)
	{
		Mat out;
		int brightness = slider1-50;
		double contrast = slider2/50;
		img.convertTo(out,-1,contrast,brightness);

		imshow("Tracker",out);
		if(waitKey(5)==27)
		{
			break;
		}
	}
	return 0;
	destroyAllWindows();
}