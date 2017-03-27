#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;
 
int main() {


    VideoCapture stream1(0);   
    if (!stream1.isOpened()) { 
        cout << "cannot open camera";
    }
    int i=0;

    while (true) {
        
        ostringstream convert;
        convert << "/home/Desktop/IIIT/3rd Year/Sem 6/CV/Assignments/Ass 0/Assignment-0/camera_images/" << i << ".png";

        Mat cameraFrame;
        stream1.read(cameraFrame);
        imshow("cam", cameraFrame);
        imwrite(convert.str().c_str(),cameraFrame);

        if (waitKey(30) >= 0)
        break;
    i++;
    }
return 0;
}
