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

	// V 채널 히스토그램 평활화
	Mat V_HE = CP.GS_histeq(hsv[2]);

	imshow("V_HE", V_HE);

	Mat hsv2[3];
	hsv2[0] = hsv[0];
	hsv2[1] = hsv[1];
	hsv2[2] = V_HE;

	// HSV' 합치기
	Mat Composite_HSVHE = CC.GS_compositeRGB(hsv2);

	imshow("Composite_HSVHE", Composite_HSVHE);

	// Convert the HSV’ image to RGB image
	Mat HSV2RGB;
	cvtColor(Composite_HSVHE, HSV2RGB, COLOR_HSV2RGB);

	imshow("HSV2RGB", HSV2RGB);

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
