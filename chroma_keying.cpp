#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
  Mat frame;
  
  VideoCapture cap(argv[1]); 
  if ( !cap.isOpened() )  
  {
    cout << "Cannot open the video file" << endl;
    return -1;
  }
  cap.read(frame); 
  double fps = cap.get(CV_CAP_PROP_FPS);

  namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); 

  Mat backgroundImage = imread(argv[2], CV_LOAD_IMAGE_COLOR);


  VideoWriter hi("./chroma_keying_output.avi",CV_FOURCC('M','J','P','G'),fps,frame.size(),true);

  while(1)
  {
    Mat frame;


    bool bSuccess = cap.read(frame); 
    Vec3b reference_value = frame.at<Vec3b>(35,35);

    int lowRangeGreen = 210;
    int highRangeGreen = 255;
    int lowRangeRed = 0;
    int highRangeRed =120;
    int lowRangeBlue = 0;
    int highRangeBlue = 255;

  
    Mat composite(frame.size(), frame.type());

    

    for(int y = 0; y < frame.rows; y++) {
      for(int x = 0; x < frame.cols; x++) {

  if (frame.at<Vec3b>(y,x)[2] >= lowRangeRed && frame.at<Vec3b>(y,x)[2] <= highRangeRed &&
            frame.at<Vec3b>(y,x)[1] >= lowRangeGreen && frame.at<Vec3b>(y,x)[1] <= highRangeGreen &&
            frame.at<Vec3b>(y,x)[0] >= lowRangeBlue && frame.at<Vec3b>(y,x)[0] <= highRangeBlue
	    
	    ) {

          composite.at<Vec3b>(y,x)[0] = backgroundImage.at<Vec3b>(y,x)[0];
          composite.at<Vec3b>(y,x)[1] = backgroundImage.at<Vec3b>(y,x)[1];
          composite.at<Vec3b>(y,x)[2] = backgroundImage.at<Vec3b>(y,x)[2];
        } else { 
          composite.at<Vec3b>(y,x)[0] = frame.at<Vec3b>(y,x)[0];
          composite.at<Vec3b>(y,x)[1] = frame.at<Vec3b>(y,x)[1];
          composite.at<Vec3b>(y,x)[2] = frame.at<Vec3b>(y,x)[2];
        }
      }
    }

    if (!bSuccess) 
    {
      cout << "Cannot read the frame from video file" << endl;
      break;
    }

    imshow("MyVideo", composite); 
    hi.write(composite);
    if(waitKey(30) >=0) 
    {
      cout << "esc key is pressed " << endl;
      break;
    }
  }
  return 0;

}

