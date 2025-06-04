#include </home/bangme/bangme/bangme/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/bangme/bangme/bangme/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

    vector<Rect> people;
    Mat img;
    while (true)
    {
        cap >> img;
        if (img.empty())
            break;
        hog.detectMultiScale(img, people);
        for (auto &rect : people)
        {
            rectangle(img, rect, red);
        }
        imshow("img", img);
        if (waitKey(100) == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}