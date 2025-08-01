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
	short int corners = 0;
	string type = "";
	int area  = 0;
	Rect boundRect[contours.size()];
	for (int i =0 ; i < contours.size();i++){
		area = contourArea(contours[i]);
		
		if (area > 1000){
		
			float peri = arcLength(contours[i],true);
			approxPolyDP(contours[i],contours[i],0.02*peri,true);
			
			
			corners = contours[i].size();
			
			boundRect[i] = boundingRect(contours[i]);
			rectangle(img,boundRect[i].tl(),boundRect[i].br(),Scalar(0,255,0),2);
			
			if(corners ==4){
				cout<<boundRect[i].x<<" "<<boundRect[i].y<<endl;
				float ratio = float(boundRect[i].width) / float(boundRect[i].height);
				if (ratio >= 0.89 && ratio <= 1.05){
					type = "Square";
				}
				else{
					type = "Rectangle";
				}
			}
			else if(corners == 3){
				type = "Trianlge";
			}
			else if(corners > 4){
				type = "Circle";
			}
			
			putText(img,type,Point(boundRect[i].x,boundRect[i].y-5),FONT_HERSHEY_PLAIN,1,Scalar(255,255,255),2);
			type = "";
			
			
		}
	}
	
}

int main() {
	
	string path = "new_img.png";
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
