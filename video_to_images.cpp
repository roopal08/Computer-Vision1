#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
  VideoCapture cap(argv[1]); // open the video file for reading
  if ( !cap.isOpened() )  // if not success, exit program
  {
    cout << "Cannot open the video file" << endl;
    return -1;
  }


  double fps = cap.get(CV_CAP_PROP_FPS);

  namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); 

  double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
  double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

  Size frameSize(static_cast<int>(width),static_cast<int>(height));
 
  int i=0,j=0;
  ostringstream convert;

    while(1)
    { 
      Mat frame;
      Mat image;

      bool bSuccess = cap.read(frame); // read a new frame from video
      //char c=cvWaitKey(0); 

    

            ostringstream convert;
            convert << "./images_of_video/" << i << ".png";

            imwrite(convert.str().c_str(),frame);
            imshow("MyVideo", frame);
            cout << convert.str().c_str() <<endl ;
        
        
        if (!bSuccess) //if not break loop
        {
          cout << "Cannot read the frame from video file" << endl;
          break;
        }


        if(waitKey(30) >= 0) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        {
	         break;
  
        }
        i++;
    }

  return 0;

}

