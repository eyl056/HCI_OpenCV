#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace std;
using namespace cv;

int main() {
	Mat lenna;
	// lenna에 이미지를 불러오기
	lenna = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/lenna.png");
	
	Mat grayImage;
	//  stuff_color_1 이미지를 8 bit gray scale 이미지로 변환하고 grayImage에 리턴
	cvtColor(lenna, grayImage, COLOR_RGB2GRAY);

	// grayImage의 이미지를 lenna 이름의 창으로 출력하기
	imshow("lenna", grayImage);

	CPixel CP;
	// 룩업 테이블을 이용한 밝기 조절 + 명암 대비 조절
	// Contrast & brightness adjustment by LUT
	// Input: 8 bit gray-scale image
	// GS_LUT_basic_contrast_brightness(cv::Mat src_image, double contrast, int brightness)
	Mat result = CP.GS_LUT_basic_contrast_brightness(grayImage, 2.0, 50);
	// result 이미지 출력
	imshow("result", result);


	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
