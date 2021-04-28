#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"
#include "Util.h"
#include "Color.h"
#include "Geometry.h"
#include "Edge.h"
#include "ImageAnalysis.h"
#include "Morph.h"
#define CAM_WIDTH 600
#define CAM_HEIGHT 400

using namespace std;
using namespace cv;


void Center_of_mass(Mat& frame, int* pX, int *pY) {
	int cnt(0); // 픽셀수 카운팅
	int mx(0);
	int my(0);
	// 면적 중심 구하기
	for (int i = 0; i < frame.size().height; i++) {
		for (int j = 0; j < frame.size().width; j++) {
			if (frame.at<uchar>(i, j) > 200) {
				cnt++;
				mx += j;
				my += i;
			}
		}
	}

	if (cnt == 0) {
		cnt = 1;
	}

	if (cnt > 0) {
		*pX = mx / cnt;
		*pY = my / cnt;
	}
}

int main() {

	// 비디오 이미지 불러오기
	VideoCapture cam(0);
	// 원래의 오리지널 이미지
	cam.set(CV_CAP_PROP_FRAME_WIDTH, CAM_WIDTH);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);

	Mat Origin_frame;
	Mat HAND_MASK = imread("C:/Users/eunyoung/Desktop/동국대학교/4학년 1학기/인간컴퓨터상호작용시스템_01/인컴 실습/HCI_LAB7/1.png", 1);

	if (!cam.isOpened()) { printf("--(!)Error opening video cam\n"); return -1; }

	while (cam.read(Origin_frame)) 
	{
		if (Origin_frame.empty()) {
			break;
		}

		// 마스크 이미지 및 웹캠을 이용해서 불러온 원본 이미지
		imshow("Origin_frame", Origin_frame);
		imshow("HAND_MASK", HAND_MASK);

		resize(Origin_frame, Origin_frame, Size(HAND_MASK.cols, HAND_MASK.rows), 0, 0, CV_INTER_LINEAR);
		imshow("resize_Origin_frame", Origin_frame);

		Mat Org_Mask = Origin_frame + HAND_MASK;
		imshow("Org_Mask", Org_Mask);
		// YCrCb 컬러모델로 변환
		Mat Ycrcb; 
		cvtColor(Org_Mask, Ycrcb, CV_BGR2YCrCb);
		imshow("Ycrcb", Ycrcb);
		// 피부 영역 추출하기
		Mat Skin_Area;
		inRange(Ycrcb, Scalar(0, 130, 90), Scalar(255, 168, 130), Skin_Area);
		imshow("Skin_Area", Skin_Area);
		// grayscale로 피부 영역 변환
		Mat Skin_Gray;
		cvtColor(Org_Mask, Skin_Gray, CV_BGR2GRAY);
		imshow("Skin_Gray", Skin_Gray);

		Mat ADD = Skin_Gray + (~Skin_Area);
		imshow("ADD", ADD);
		// 손바닥 영역 추출해내고 이진화
		Mat thresh;
		threshold(ADD, thresh, 200, 255, THRESH_BINARY);
		imshow("thresh", thresh);

		Mat temp;
		erode((~Skin_Area), temp, Mat(3, 3, CV_8U, Scalar(1)));
		imshow("temp", temp);

		// 무게 중심점을 이용한 손바닥 중심점 찾기
		int cx, cy;
		Center_of_mass(Skin_Area, &cx, &cy);
		
		circle(Origin_frame, Point(cx, cy), 50, Scalar(0, 0, 255), 1);
		imshow("center_Org_Frame", Origin_frame);

		// 손바닥 영역만 추출
		Mat Center_Palm = Skin_Gray.clone();
		circle(Center_Palm, Point(cx, cy), 50, Scalar(0, 0, 0), -1);
		imshow("Center_Palm", Center_Palm);
		
		Mat SUB = Skin_Gray - Center_Palm;
		imshow("SUB", SUB);

		// 해당 영역에 엣지 디렉터를 사용하여 손금만 추출
		Mat CannyEdge;
		Canny(SUB, CannyEdge, 40, 110);
		imshow("CannyEdge", CannyEdge);
		// 필요없는 원 부분 제거
		circle(CannyEdge, Point(cx, cy), 50, Scalar(0, 0, 0), 4);
		imshow("Result", CannyEdge);

		CMorph CM;
		Mat closing;
		closing= CM.GS_closing(CannyEdge, MORPH_RECT, 1);
		imshow("closing", closing);

		char c = (char)waitKey(10);
		if (c == 27) break;
	}
	return 0;
}
