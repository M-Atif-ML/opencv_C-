#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>

using namespace std;
using namespace cv;
// color detection 

Mat imgGray,imgBlur,imgCanny,imgDil;

void getContours(Mat imgDil,Mat img){
	
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	
	findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
	// drawContours(img,contours,0,Scalar(255,0,255),2);
	
	cout<<endl;
	for (int i =0 ; i < contours.size();i++){
		int area = contourArea(contours[i]);

		if (area > 1000){
			cout<<contours[i].size()<<endl;
			float peri = arcLength(contours[i],true);
			approxPolyDP(contours[i],contours[i],0.02*peri,true);
			
			drawContours(img,contours,i,Scalar(255,0,255),2);
			//cout<<contours[i].size()<<endl;
			
			
		}
	}
	
}

int main() {
	
	string path = "shapes.png";
	Mat img = imread(path);
	
	// preprocessing
	cvtColor(img,imgGray,COLOR_BGR2GRAY);
	GaussianBlur(imgGray,imgBlur,Size(3,3),3,0);
	Canny(img,imgCanny,25,75);
	Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
	dilate(imgCanny,imgDil,kernel);
	
	getContours(imgDil,img);
	
	imshow("Shapes: ",img);
	
	
	waitKey(0); 
	
    	return 0;
}
