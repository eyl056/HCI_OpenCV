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
	Mat Lenna = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/lenna.png");
	Mat Jenny = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/jenny.jpg");

	// 원본 사진 출력
	imshow("Lenna", Lenna);
	imshow("Jenny", Jenny);

	// 컬러 이미지를 흑백 이미지로 전환(gray_scale)
	Mat Gray_Lenna, Gray_Jenny;
	cvtColor(Lenna, Gray_Lenna, CV_BGR2GRAY);
	cvtColor(Jenny, Gray_Jenny, CV_BGR2GRAY);

	// gray scale 이미지 출력
	imshow("Gray_Lenna", Gray_Lenna);
	imshow("Gray_Jenny", Gray_Jenny);

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
