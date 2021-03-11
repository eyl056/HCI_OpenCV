#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image = Mat(Size(300, 400), CV_8UC1, Scalar(255)); // 8��Ʈ 1ä�� Unsigned Char image
	image(Rect(0, 0, 300, 200)) = Scalar(1); // �簢���� image ����

	putText(image, "2017112094", Point(50, 100), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 255)); // image�� �ؽ�Ʈ �߰�
	putText(image, "LeeEunYoung", Point(50, 300), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 0)); // image�� �ؽ�Ʈ �߰�

	cout << "2017112094 ������" << endl; // ���
	imshow("image", image); // image�� ȭ�鿡 ����

	waitKey(); // �Է� ��� (0�̰ų� ��������� ���� ���)
	return 0;
}