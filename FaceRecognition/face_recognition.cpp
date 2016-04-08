//
//Author : Arun Jayan 
//
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	//create cascade classifier object
	CascadeClassifier face_cascade;
	face_cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml");
	
	//create video capture object
	VideoCapture camera;
	camera.open(0);//open the default camera 
	
	Mat frame;
	Mat gray;
	
	//creates a empty window
	namedWindow("frame",CV_WINDOW_AUTOSIZE);
	
	while(true)
    {
		camera>>frame; //read frames 
		
		//covert frame to grayscale using cvtColor()
		cvtColor(frame,gray,CV_BGR2GRAY);
		equalizeHist(gray,gray);
		
		std::vector<Rect> faces; // to store detected faces . 
		
		face_cascade.detectMultiScale(gray,faces,1.1,3,CV_HAAR_FIND_BIGGEST_OBJECT|CV_HAAR_SCALE_IMAGE,Size(30,30));
		
		//draw a rectangle around all detected faces 
		for(int i=0;i<faces.size();i++)
		{
			Point p1(faces[i].x+faces[i].width,faces[i].height+faces[i].height); //define points for drawing rectangle 
			Point p2(faces[i].x,faces[i].y); //define points2 
			cout<<faces[i]<<endl;
			rectangle(frame,p1,p2,Scalar(0,200,255),3,0,0); //draw the rectagle 
		}
		imshow("frame",frame);
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
	}
	
	return 0;
}
	

