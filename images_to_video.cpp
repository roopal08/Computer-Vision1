#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {

  Mat im;
  ostringstream convert;

    convert << "./images_of_video/1.png";
  im = imread(convert.str().c_str(),CV_LOAD_IMAGE_COLOR);


  const string fraps  = argv[1];
  int fps = atoi(fraps.c_str());

  double width = im.cols;
  double height = im.rows;

  Size frameSize(static_cast<int>(width),static_cast<int>(height));

  VideoWriter hi("./output_video.avi",CV_FOURCC('M','J','P','G'),fps,frameSize,true);

 
  int j=0;


    while(1)
    { 
      Mat frame;
      Mat image;
 

	       cout << width << endl;
         ostringstream convert;
          convert << "./images/" << j << ".png";

          cout << convert.str().c_str() << endl;
          image = imread(convert.str().c_str(),CV_LOAD_IMAGE_COLOR);

          imshow("img", image);

        hi.write(image);

        j++;

        if(waitKey(30) >= 0) 
        {
	         break;
        }
    j++;
  }

  return 0;

}

