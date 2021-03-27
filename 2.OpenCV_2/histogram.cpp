#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace std;
using namespace cv;

int main() {

	// 사진 불러오기
	Mat Lenna = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/lenna.png");
	Mat stuff_color_1 = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/stuff_color_1.png");

	imshow("Lenna", Lenna);
	imshow("stuff_color_1", stuff_color_1);

	// 컬러 이미지를 흑백 이미지로 전환(gray_scale)
	Mat Gray_Lenna;
	cvtColor(Lenna, Gray_Lenna, CV_BGR2GRAY);
	Mat Gray_stuff_color_1;
	cvtColor(stuff_color_1, Gray_stuff_color_1, CV_BGR2GRAY);

	imshow("Gray_Lenna", Gray_Lenna);
	imshow("Gray_stuff_color_1", Gray_stuff_color_1);


	CPixel CP;
	// 8-bit Grayscale Image를 입력으로 받아 히스토그램을 생성
	Mat Lenna_HIST = CP.GS_imhist(Gray_Lenna);
	Mat stuff_color_1_HIST = CP.GS_imhist(Gray_stuff_color_1);

	// 히스토그램 출력
	imshow("Lenna_HIST", Lenna_HIST);
	imshow("stuff_color_1_HIST", stuff_color_1_HIST);

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}

