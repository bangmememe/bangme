#include </home/bangme/bangme/bangme/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/bangme/bangme/bangme/opencv/data/";

int main()
{
    VideoCapture cap(0);

    QRCodeDetector qrDetector;
    vector<Point> points;
    String info;
    Mat img;
    while (true)
    {
        cap >> img;
        if (img.empty())
            break;
        qrDetector.detect(img, points);

        polylines(img, points, true, red, 2);

        imshow("img", img);
        if (waitKey(33) == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}