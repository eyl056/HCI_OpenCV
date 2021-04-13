#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"
#include "Util.h"
#include "Color.h"
#include "Geometry.h"
#include "Edge.h"

using namespace std;
using namespace cv;

int main() {

	// 사진 불러오기
	Mat Jenny = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/jenny.jpg");
	Mat Rice = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/rice.png");

	Mat Gray_Jenny, Gray_Rice;
	// convert to Gray scale image
	cvtColor(Jenny, Gray_Jenny, CV_BGR2GRAY);
	cvtColor(Rice, Gray_Rice, CV_BGR2GRAY);

	// gray scale image 출력
	imshow("Gray_Jenny", Gray_Jenny);
	imshow("Gray_Rice", Gray_Rice);

	CEdge CE;

	Mat Canny_Jenny, Canny_Rice;

	// 캐니 에지 추출 : Canny() 함수 이용  (Extraction canny edge : using cv::Canny())
	Canny_Jenny = CE.GS_canny_edge_Canny(Gray_Jenny, 100, 255);
	Canny_Rice = CE.GS_canny_edge_Canny(Gray_Rice, 100, 255);
	

	// 이미지 출력
	imshow("Canny_Jenny", Canny_Jenny);
	imshow("Canny_Rice", Canny_Rice);

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}

