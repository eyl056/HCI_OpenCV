#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"
#include "Util.h"
#include "Color.h"
#include "Geometry.h"
#include "Edge.h"
#include "ImageAnalysis.h"

using namespace std;
using namespace cv;

int main() {

	// 노트북 내장 웹캠의 카메라 번호는 0이다.
	VideoCapture cam(0);
	Mat temp;

	// 노트북 카메라 정보의 유무를 확인해준다.
	if (!cam.isOpened())
	{
		printf("Can't open the camera");
		return -1;
	}

	// 웹캠 영상을 받아와 출력한다.
	while (1) {
		cam.read(temp);

		imshow("temp", temp);

		if (waitKey(1) == 27)
			break;
	}


	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
