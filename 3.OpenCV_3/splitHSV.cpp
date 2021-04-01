#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"
#include "Util.h"
#include "Color.h"

using namespace std;
using namespace cv;

int main() {

	// 사진 불러오기
	Mat Jenny = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/jenny.jpg");

	CColor CC;
	CPixel CP;

	// 원본 RGB 이미지 출력
	imshow("Jenny", Jenny);

	Mat hsv[3];
	Mat HSV_Jenny;
	// RGB color image to HSV image
	cvtColor(Jenny, HSV_Jenny, COLOR_RGB2HSV);

	// HSV 이미지 출력
	imshow("HSV_Jenny", HSV_Jenny);

	// HSV 분리
	split(HSV_Jenny, hsv);

	imshow("H_Jenny", hsv[0]);
	imshow("S_Jenny", hsv[1]);
	imshow("V_Jenny", hsv[2]);

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
