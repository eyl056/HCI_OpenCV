#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace std;
using namespace cv;

int main() {

	// 사진 불러오기
	Mat Lenna = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/lenna.png");

	imshow("Lenna", Lenna);

	// 컬러 이미지를 흑백 이미지로 전환(gray_scale)
	Mat Gray_Lenna;
	cvtColor(Lenna, Gray_Lenna, CV_BGR2GRAY);

	imshow("Gray_Lenna", Gray_Lenna);

	CPixel CP;

	// Binarization by adaptive thresholding
	Mat AThreshold_Lenna = CP.GS_adaptive_threshold(Gray_Lenna, 150, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY);

	imshow("Adaptive_Threshold_Lenna", AThreshold_Lenna);

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}