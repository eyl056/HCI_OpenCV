
#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Filter.h"
#include "Util.h"
#include "Color.h"
#include "Geometry.h"
#include "Edge.h"
#include "ImageAnalysis.h"
#include "Morph.h"

using namespace std;
using namespace cv;

int main() {

	VideoCapture cam(0);
	Mat Rice = imread("C:/Users/eunyoung/Desktop/동국대학교/4학년 1학기/인간컴퓨터상호작용시스템_01/인컴 실습/HCI_6_배포용/rice.png");
	Mat Stuff_Color = imread("C:/Users/eunyoung/Desktop/동국대학교/4학년 1학기/인간컴퓨터상호작용시스템_01/인컴 실습/HCI_6_배포용/stuff_color.png");

	Mat Gray_Rice;
	Mat Gray_Stuff_Color;

	cvtColor(Rice, Gray_Rice, CV_BGR2GRAY);
	cvtColor(Stuff_Color, Gray_Stuff_Color, CV_BGR2GRAY);

	//imshow("Gray_Rice", Gray_Rice);
	//imshow("Gray_Stuff_Color", Gray_Stuff_Color);

	CMorph CM;
	CImageAnalysis CI;
	
	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(11, 11), Point(1, 1));

	// (1)
	Mat Erosion_Rice;
	Mat Erosion_Stuff_Color;
	erode(Gray_Rice, Erosion_Rice, kernel);
	erode(Gray_Stuff_Color, Erosion_Stuff_Color, kernel);
	//imshow("Erosion_Rice", Erosion_Rice);
	//imshow("Erosion_Stuff_Color", Erosion_Stuff_Color);

	// (2)
	Mat Openning_Rice;
	Mat Openning_Stuff_Color;
	dilate(Erosion_Rice, Openning_Rice, kernel);
	dilate(Erosion_Stuff_Color, Openning_Stuff_Color, kernel);
	//imshow("Openning_Rice", Openning_Rice);
	//imshow("Openning_Stuff_Color", Openning_Stuff_Color);

	// (3)
	Mat Tophat_Rice = Gray_Rice - Openning_Rice;
	Mat Tophat_Stuff_Color = Gray_Stuff_Color - Openning_Stuff_Color;
	//imshow("Tophat_Rice", Tophat_Rice);
	//imshow("Tophat_Stuff_Color", Tophat_Stuff_Color);

	// (4)
	Mat Binary_Rice;
	Mat Binary_Stuff_Color;
	threshold(Tophat_Rice, Binary_Rice, 0, 255, THRESH_BINARY | THRESH_OTSU);
	threshold(Tophat_Stuff_Color, Binary_Stuff_Color, 0, 255, THRESH_BINARY | THRESH_OTSU);
	//imshow("Binary_Rice", Binary_Rice);
	//imshow("Binary_Stuff_Color", Binary_Stuff_Color);

	// (5)
	Mat Labeling_Rice = CI.GS_findContours(Binary_Rice);
	Mat Labeling_Stuff_Color = CI.GS_findContours(Binary_Stuff_Color);
	imshow("Labeling_Rice", Labeling_Rice);
	imshow("Labeling_Stuff_Color", Labeling_Stuff_Color);

	waitKey(); // 입력 대기 (0이거나 비워있으면 키 입력 무한 대기)
	return 0;
}
