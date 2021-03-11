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
	// 각각의 이미지를 stuff_color_1, stuff_color_2 이름의 창으로 출력하기
	imshow("stuff_color_1", stuff_color_1);
	imshow("stuff_color_2", stuff_color_2);

	CPixel CP;
	// CPixel 클래스의 GS_add_image 함수를 사용하여 두 이미지의 합을 구하고 result에 넣음
	Mat result = CP.GS_add_image(stuff_color_1, stuff_color_2);
	// result 이미지 출력
	imshow("result", result);

	// 콘솔창에 이미지 사이즈 출력
	cout << stuff_color_1.size << endl;
	cout << stuff_color_2.size << endl;

	/*Mat temp;
	add(stuff_color_1, stuff_color_2, temp);
	imshow("temp", temp);

	Mat temp2 = stuff_color_1 + stuff_color_2;
	imshow("temp2", temp2);*/

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
