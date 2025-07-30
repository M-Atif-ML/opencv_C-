#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
// color detection 


int main() {
	string Path = "lambo.png";
	Mat img = imread(Path),imgHSV,mask;
	
	cvtColor(img,imgHSV,COLOR_BGR2HSV);
	
	int hmin = 0,smin = 110,vmin = 153;
	int hmax = 19,smax = 240,vmax = 255; 
	
	namedWindow("Trackbars",(640,200));
        createTrackbar("Hue min:", "Trackbars", &hmin, 179);
        createTrackbar("Hue max:", "Trackbars", &hmax, 179);
        createTrackbar("Sat min:", "Trackbars", &smin, 255);
        createTrackbar("Sat max:", "Trackbars", &smax, 255);
        createTrackbar("Val min:", "Trackbars", &vmin, 255);
        createTrackbar("Val max:", "Trackbars", &vmax, 255);
	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);

		imshow("Original", img);
		imshow("HSV", imgHSV);
		imshow("Mask", mask);

		// Press 'q' or 'Esc' to quit
		char key = (char)waitKey(1);
		if (key == 27 || key == 'q') { // 27 is ASCII for ESC
		    break;
        }
    }
	
	
    	return 0;
}

