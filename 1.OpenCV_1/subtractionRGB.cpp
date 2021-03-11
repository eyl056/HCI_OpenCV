#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"

using namespace std;
using namespace cv;

int main() {
	Mat stuff_color_1, stuff_color_2;
	// stuff_color_1, stuff_color_2에 각각 이미지를 색 정보를 포함하여 불러오기(DEFAULT, 'IMREAD_COLOR' or '1')
	stuff_color_1 = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/stuff_color_1.png");
	stuff_color_2 = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/stuff_color_2.png");
	
	int j = 100;
	int i = 100;

	int lBlue, lGreen, lRed;
	lBlue = 0;
	lGreen = 0;
	lRed = 0;

	lBlue = stuff_color_1.at<Vec3b>(j, i)[0];
	lGreen = stuff_color_1.at<Vec3b>(j, i)[1];
	lRed = stuff_color_1.at<Vec3b>(j, i)[2];

	cout << "stuff_color_1 이미지의 (100, 100) 좌표의 R, G, B값" << " R : " << lRed << " G : " << lGreen << " B : " << lBlue << endl;

	int a = 100;
	int b = 100;

	int oBlue, oGreen, oRed;
	oBlue = 0;
	oGreen = 0;
	oRed = 0;

	oBlue = stuff_color_2.at<Vec3b>(b, a)[0];
	oGreen = stuff_color_2.at<Vec3b>(b, a)[1];
	oRed = stuff_color_2.at<Vec3b>(b, a)[2];

	cout << "stuff_color_2 이미지의 (100, 100) 좌표의 R, G, B값" << " R : " << oRed << " G : " << oGreen << " B : " << oBlue << endl;

	CPixel CP;
	// CPixel 클래스의 GS_subtract_image 함수를 사용하여 두 영상 간 뺄셈을 구하고 result에 넣음
	Mat result = CP.GS_subtract_image(stuff_color_1, stuff_color_2);
	// result 이미지 출력
	imshow("result", result);

	int rBlue, rGreen, rRed;
	rBlue = 0;
	rGreen = 0;
	rRed = 0;

	rBlue = result.at<Vec3b>(b, a)[0];
	rGreen = result.at<Vec3b>(b, a)[1];
	rRed = result.at<Vec3b>(b, a)[2];

	cout << " 뺄셈 연산 후 이미지의 (100, 100) 좌표의 R, G, B값" << " R : " << rRed << " G : " << rGreen << " B : " << rBlue << endl;

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
