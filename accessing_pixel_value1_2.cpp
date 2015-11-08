#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,const char** argv)
{
	Mat img = imread("sample.png");//image loaded
	int col;
	if(!img.data)//if image can't be loaded terminate 
	{
		cout<<"Image can't be loaded"<<endl;
		return -1;
	}
	cout<<img.cols<<"x"<<img.rows<<endl;//dimension of image
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			Vec3b color = img.at<Vec3b>(Point(j,i));
			if(color[0]>120&&color[1]>120&&color[2]>120)
			{
				color[0]=0;
				color[1]=0;
				color[2]=0;
			}
			else
			{
				color[0]=255;
				color[1]=255;
				color[2]=255;
			}
			img.at<Vec3b>(Point(j,i))=color;
		}
	}
	imshow("sample",img);
	waitKey(0);
	return 0;

}