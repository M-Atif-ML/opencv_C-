#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
// basic functions 
int main() {
    string path = "download.jpeg";
    Mat img = imread(path),imgResize,imgCrop;
    
    
 
    // Resize image 3x bigger
    resize(img, imgResize, Size(), 3, 3);

    // Crop a 200x200 region starting from (100,100)
    Rect roi(50, 50, 70, 70);
    imgCrop = img(roi);  // Make sure image is large enough

    // Show both images
    //imshow("Resized Image", imgResize);
    imshow("Cropped Image", imgCrop);
    imshow("Original image: ",img);
    waitKey(0);
    return 0;
}
