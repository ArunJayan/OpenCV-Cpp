//################################################################################################
//Author : Arun Jayan
//Email ID : arunjayan32@gmail.com
//################################################################################################
//log : 
//modified : 5 Nov 2015 --> started and learned opencv C++ (github.com/ArunJayan/OpenCV-Cpp)
//modified : 6 Nov 2015 --> done thresholding etc. and started with color detection using inRange(),familarized with rectangle()
//last modified : 7 Nov 2015 --> has trouble with Mat img = frame (here we pass reference not data, so we have to use, Mat img =frame.clone())
//                 counted the white pixel
//                 detected the presence of particular colour in our ROI
//####################################################################################################
//TODO : 1.add change in position of ROI after a detection and also random positioning
//       2.time measurement for each detection 
//       3.generate a log file
//####################################################################################################

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
int x = 0;
int y = 0;
int x_origin = 0;
int y_origin = 0;
int t = 50;
Mat imgOriginal;
//imgROI,imgHSV,imgThresholded;
int count = 0;
Mat fillROI(Mat image,int R,int G,int B)
{
     rectangle(image,Point(x,y),Point(x+t,y+t),Scalar(B,G,R),-1);
     return image;
}

int count_ones(Mat thresh)
{
   int c= 0;
    for(int i =0;i<thresh.rows;i++)
    {
      uchar* pixel = thresh.ptr<uchar>(i);
      for(int j=0;j<thresh.cols;j++)
      {
        if(pixel[j]!=0)
        {
          c = c +1; //counting white pixels
        }
      }
    }

    //cout<<c<<endl;
    return c;
}

void check_occurance(int ones,Mat img)
{
    if(ones>1050)
    {/*
      //change the color
      for(int i=0;i<img.rows;i++)
      {
        for(int j=0;j<img.cols;j++)
        {
          Vec3b color = img.at<Vec3b>(Point(j,i));
          color[0]=0; //B
          color[0]=255;//G
          color[0]=0;//R
          img.at<Vec3b>(Point(j,i))=color;
        }
      }*/
        imgOriginal = fillROI(imgOriginal,0,255,0);
        y = y_origin;
        int random = rand() % 400 +1; //random num
        cout<<random<<endl;
        x = x + random; //modified position
        y = y + random;// ""         ""

    }
    else
    {
      //no change
      imgOriginal = fillROI(imgOriginal,255,0,0);
    }
}

 int main( int argc, char** argv )
 {
    Mat imgROI,imgHSV,imgThresholded;
    VideoCapture cap(0); //capture the video from webcam

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the web cam" << endl;
         return -1;
    }
/*
low 136 137 112
high : 147 160 168
*/
  int iLowH = 133;
  int iHighH = 156;

  int iLowS = 140; 
  int iHighS = 210;

  int iLowV = 71;
  int iHighV = 250;

    while (true)
    {
    Mat frame;
    bool bSuccess = cap.read(frame); // read a new frame from video
    if (!bSuccess) //if not success, break loop
        {
           cout << "Cannot read a frame from video stream" << endl;
           break;
        }

   Rect roi(x,y,50,50);
   Mat img = frame.clone(); 
   imgOriginal = frame.clone();
   imgROI = img(roi);//Region of interest
   imgOriginal = fillROI(imgOriginal,255,0,0);
   cvtColor(imgROI, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
   inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
   int ones = count_ones(imgThresholded);
   check_occurance(ones,imgOriginal);
   cout<<ones<<endl;
   imshow("Thresholded Image", imgThresholded); //show the thresholded image
   imshow("Original", imgOriginal); //show the original image
   //imshow("frame",frame);
   //imshow("ROI",imgROI);

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
            cout << "esc key is pressed by user" << endl;
            break; 
       }
    }

   return 0;
   destroyAllWindows();
}