#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

/* get_positions: a function to retrieve the center of the detected blobs.
 * largely based on OpenCV's "Creating Bounding boxes and circles for contours" tutorial.
 */
std::vector<cv::Point2f> get_positions(cv::Mat& image)
{
    if (image.channels() > 1)
    {
        std::cout << "get_positions: !!! Input image must have a single channel" << std::endl;
        return std::vector<cv::Point2f>();
    }

    std::vector<std::vector<cv::Point> > contours;
    cv::findContours(image, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);

    // Approximate contours to polygons and then get the center of the objects
    std::vector<std::vector<cv::Point> > contours_poly(contours.size());
    std::vector<cv::Point2f> center(contours.size());
    std::vector<float> radius(contours.size());
    for (unsigned int i = 0; i < contours.size(); i++ )
    {
        cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 5, true );
        cv::minEnclosingCircle((cv::Mat)contours_poly[i], center[i], radius[i]);
    }

    return center;
} 
int main()
{
    // Open the capture device. My webcam ID is 0:
	cv::Mat img = cv::imread("blob_sample.png");
	if(!img.data)
	{
		std::cout<<"image can not be loaded"<<std::endl;
		return -1;
	}
	

    // Let's create a few window titles for debugging purposes
    std::string wnd1 = "Input", wnd2 = "Red Objs", wnd3 = "Output";   

    // These are the HSV values used later to isolate RED-ish colors
    int low_h = 0, low_s = 253, low_v = 253;
    int high_h = 0, high_s = 255, high_v = 255;

    cv::Mat hsv_frame, red_objs;
        cv::Mat orig_frame = img.clone();
        cv::imshow(wnd1, orig_frame);
  // Convert BGR frame to HSV to be easier to separate the colors
        cv::cvtColor(img, hsv_frame, CV_BGR2HSV);

        // Isolate red colored objects and save them in a binary image
        cv::inRange(hsv_frame,
                    cv::Scalar(low_h,  low_s,  low_v),
                    cv::Scalar(high_h, high_s, high_v),
                    red_objs);

        // Remove really small objects (mostly noises)
        cv::erode(red_objs, red_objs, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));
        cv::dilate(red_objs, red_objs, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7)));

        cv::Mat objs = red_objs.clone();
        cv::imshow(wnd2, objs);
        // Retrieve a vector of points with the (x,y) location of the objects
        std::vector<cv::Point2f> points = get_positions(objs);
		char text[30];
        // Draw a small green circle at those locations for educational purposes
        for (unsigned int i = 0; i < points.size(); i++)
        {
            cv::circle(img, points[i], 3, cv::Scalar(0, 255, 0), -1, 8, 0);
            sprintf(text, "(%d,%d)",int(points[i].x),int(points[i].y));//otherwise print coodinates 
            cv::putText(img, text, cv::Point(points[i].x,points[i].y), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8, cv::Scalar(255,0,0));
            std::cout<<points[i].x<<" "<<points[i].y<<std::endl;}

        cv::imshow(wnd3, img);
		cv::waitKey(0);
    

	cv::destroyAllWindows();

    return 0;
}
