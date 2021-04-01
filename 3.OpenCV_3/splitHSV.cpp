#include <iostream>
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"
#include "Util.h"
#include "Color.h"

using namespace std;
using namespace cv;

int main() {

	// ���� �ҷ�����
	Mat Jenny = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/jenny.jpg");

	CColor CC;
	CPixel CP;

	// ���� RGB �̹��� ���
	imshow("Jenny", Jenny);

	Mat hsv[3];
	Mat HSV_Jenny;
	// RGB color image to HSV image
	cvtColor(Jenny, HSV_Jenny, COLOR_RGB2HSV);

	// HSV �̹��� ���
	imshow("HSV_Jenny", HSV_Jenny);

	// HSV �и�
	split(HSV_Jenny, hsv);

	imshow("H_Jenny", hsv[0]);
	imshow("S_Jenny", hsv[1]);
	imshow("V_Jenny", hsv[2]);

	waitKey(); // �Է� ��� (0�̰ų� ��������� Ű �Է� ���� ���)
	return 0;
}
