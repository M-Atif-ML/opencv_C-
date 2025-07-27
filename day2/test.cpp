#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
int main() {
    string path = "download.jpeg";
    Mat img = imread(path);
    Mat imgGray,blur,canny;
    
    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(img,blur,Size(7,7),5,0);
    Canny(img,canny,50,150);
    imshow("Image Gray",imgGray);
    imshow("Blur: ",blur);
    imshow("Canny: ",canny);
    
    waitKey(0);
}
