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
	Mat Lenna = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/lenna.png");
	Mat Jenny = imread("C:/Users/eunyoung/Desktop/1.OpenCV_1/image/jenny.jpg");

	// ���� ���� ���
	imshow("Lenna", Lenna);
	imshow("Jenny", Jenny);

	// �÷� �̹����� ��� �̹����� ��ȯ(gray_scale)
	Mat Gray_Lenna, Gray_Jenny;
	cvtColor(Lenna, Gray_Lenna, CV_BGR2GRAY);
	cvtColor(Jenny, Gray_Jenny, CV_BGR2GRAY);

	// gray scale �̹��� ���
	imshow("Gray_Lenna", Gray_Lenna);
	imshow("Gray_Jenny", Gray_Jenny);

	waitKey(); // �Է� ��� (0�̰ų� ��������� Ű �Է� ���� ���)
	return 0;
}
