#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
// basic functions 
int main() {
    string path = "download.jpeg";
    Mat img = imread(path);
    Mat imgGray,blur,canny,imgDil,erodImg;
    
    cvtColor(img,imgGray,COLOR_BGR2GRAY);
    GaussianBlur(img,blur,Size(7,7),5,0);
    Canny(blur,canny,50,150);
    
    Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    dilate(canny,imgDil,kernel);
    
    erode(imgDil,erodImg,kernel);
    
    
    imshow("Image Gray",imgGray);
    imshow("Blur: ",blur);
    imshow("Canny: ",canny);
    imshow("Dilated image: ",imgDil);
    imshow("Eroded image:",erodImg);
    
    waitKey(0);
}
