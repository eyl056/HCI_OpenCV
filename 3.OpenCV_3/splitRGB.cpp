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

	// ä�� �и��� ���� �迭
	Mat bgr[3];

	// RGB �÷� ���� �и�, ���࿡ ��ϵ� �����̸� �� ä�ο� �Ҵ�
	// * ���� * BGR ������ ������ 
	CC.GS_splitRGB(Jenny, bgr);

	// ���� ���� ���
	imshow("Jenny", Jenny);
	// Red image ���
	imshow("Red_Jenny", bgr[2]);
	// Green Image ���
	imshow("Green_Jenny", bgr[1]);
	// Blue image ���
	imshow("Blue_Jenny", bgr[0]);

	waitKey(); // �Է� ��� (0�̰ų� ��������� Ű �Է� ���� ���)
	return 0;
}
