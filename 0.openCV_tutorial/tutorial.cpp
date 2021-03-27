#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image = Mat(Size(300, 400), CV_8UC1, Scalar(255)); // 8비트 1채널 Unsigned Char image
	image(Rect(0, 0, 300, 200)) = Scalar(1); // 사각형의 image 생성

	putText(image, "2017112094", Point(50, 100), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 255)); // image에 텍스트 추가
	putText(image, "LeeEunYoung", Point(50, 300), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 0)); // image에 텍스트 추가

	cout << "2017112094 이은영" << endl; // 출력
	imshow("image", image); // image를 화면에 띄우기

	waitKey(); // 입력 대기 (0이거나 비워있으면 무한 대기)
	return 0;
}