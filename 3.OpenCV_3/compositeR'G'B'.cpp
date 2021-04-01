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

	// 채널 분리를 위한 배열
	Mat bgr[3];

	// RGB 컬러 공간 분리, 만약에 명암도 영상이면 각 채널에 할당
	// * 주의 * BGR 순서로 가져옴 
	CC.GS_splitRGB(Jenny, bgr);

	// 원본 사진 출력
	imshow("Jenny", Jenny);
	// Red image 출력
	imshow("Red_Jenny", bgr[2]);
	// Green Image 출력
	imshow("Green_Jenny", bgr[1]);
	// Blue image 출력
	imshow("Blue_Jenny", bgr[0]);

	// 히스토그램 평활화
	Mat Red_HE = CP.GS_histeq(bgr[2]);
	Mat Green_HE = CP.GS_histeq(bgr[1]);
	Mat Blue_HE = CP.GS_histeq(bgr[0]);

	// 이미지 출력
	imshow("Red_HE", Red_HE);
	imshow("Green_HE", Green_HE);
	imshow("Blue_HE", Blue_HE);

	Mat bgr_he[3];

	bgr_he[2] = Red_HE;
	bgr_he[1] = Green_HE;
	bgr_he[0] = Blue_HE;

	// RGB 채널을 조합하여 RGB 컬러 공간으로 반환한다.
	Mat Composite_Jenny = CC.GS_compositeRGB(bgr_he);

	imshow("Composite_Jenny", Composite_Jenny);


	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
