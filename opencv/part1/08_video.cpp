#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/bangme/bangme/bangme/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");
    Mat frame;
    while (true)
    {
        cap >> frame;
        imshow("frame", frame);
        if (waitKey(33) == 27) // fps 조절 숫자.
            break;
    }

    return 0;
}