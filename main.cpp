#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "integralImage.hpp"

using namespace std;
// just a simple test.

int main(int argc, char** argv)
{
    cv::Mat img(3,4, CV_8UC1, cv::Scalar(1,0,255));
    cout << img << endl;
    IntegralImg *integral = new IntegralImg(img);
    cout << integral->SummationOverBoundingBox(0,3,8,11);
    delete integral;
    return 0;
}
