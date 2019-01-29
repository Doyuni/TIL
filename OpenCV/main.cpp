#include "opencv2/opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;
int main()
{
    string filepath("Lena.jpg"); // load the image
    Mat origin_img = imread(filepath, IMREAD_COLOR);
    if (origin_img.empty())
    {
        cout << "이미지를 찾을 수 없습니다." << endl;
        return -1;
    }
    imshow("Lena", origin_img);
    waitKey();
    return 0;
}