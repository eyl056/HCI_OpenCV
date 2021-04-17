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

	VideoCapture cam(0);
	Mat Template = imread("C:/Users/eunyoung/Downloads/Lab_5_OpenCV_5/Lab_5_OpenCV_5/capture1.png");
	Mat temp;
	Mat Result;


	CImageAnalysis IA;

	while (1) {
		cam.read(temp);

		//imshow("temp", temp);

		// 템플릿 매칭(template matching)
		Result = IA.GS_templateMatching(temp, Template);

		imshow("Result", Result);

		if (waitKey(1) == 27)
			break;
	}


	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}

