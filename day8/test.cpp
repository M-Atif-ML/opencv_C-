#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>

using namespace std;
using namespace cv;
// color detection 


int main() {
	
	VideoCapture cap(0);
	
	Mat img;
	
	
	while (true){
		CascadeClassifier faceCascade;
		faceCascade.load("haarcascade_frontalface_default.xml");
		
		vector<Rect> faces;
		
		faceCascade.detectMultiScale(img,faces,1.1,10);
	
		cap.read(img);
		for (int i = 0; i < faces.size();i++){
			rectangle(img,faces[i].tl(),faces[i].br(),Scalar(0,255,0),1);
		}
		
		imshow("image: ",img);
		waitKey(1);
	}
	
	
	
	imshow("Image: ",img);	
	
	
	waitKey(0); 
	
    	return 0;
}

