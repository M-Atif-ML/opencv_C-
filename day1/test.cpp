#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// image:
/*int main() {
	string path = "download.jpeg";
	Mat img = imread(path);
	imshow("Image",img);
	
	waitKey(0);
	

}*/

// video:

int main(){
	VideoCapture cap(0);
	Mat img;
	while(true){
		cap.read(img);
		
		imshow("Image",img);
		waitKey(1);
	}
}
