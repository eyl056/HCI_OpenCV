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

	// V ä�� ������׷� ��Ȱȭ
	Mat V_HE = CP.GS_histeq(hsv[2]);

	imshow("V_HE", V_HE);

	Mat hsv2[3];
	hsv2[0] = hsv[0];
	hsv2[1] = hsv[1];
	hsv2[2] = V_HE;

	// HSV' ��ġ��
	Mat Composite_HSVHE = CC.GS_compositeRGB(hsv2);

	imshow("Composite_HSVHE", Composite_HSVHE);

	// Convert the HSV�� image to RGB image
	Mat HSV2RGB;
	cvtColor(Composite_HSVHE, HSV2RGB, COLOR_HSV2RGB);

	imshow("HSV2RGB", HSV2RGB);

	waitKey(); // �Է� ��� (0�̰ų� ��������� Ű �Է� ���� ���)
	return 0;
}
