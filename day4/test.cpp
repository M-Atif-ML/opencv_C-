#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
// basic functions 
int main() {
    // blank image
    Mat img(512,512,CV_8UC3,Scalar(255,255,255));
    
    circle(img,Point(256,256),155,Scalar(0,50,2),FILLED);
    // circle(img,point,size,color);
    // circle(img,point,size,color,thickness);
    rectangle(img,Point(130,226),Point(382,286),Scalar(255,255,255),FILLED);
    
    line(img,Point(130,296),Point(382,296),Scalar(255,255,255),2);
    
    putText(img,"Atif khan",Point(12,23),FONT_HERSHEY_DUPLEX,0.75,Scalar(0,69,255),2);
    // putText(img,string,Point,Font_type,size,color,thickness);
    imshow("Blue image: ",img);
    waitKey(0);
    return 0;
}
