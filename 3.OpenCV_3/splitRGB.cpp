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

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
