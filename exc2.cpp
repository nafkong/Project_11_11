#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("18.jpg");
	Mat grayMat, dstMat;
	cvtColor(srcMat, grayMat, COLOR_BGR2GRAY);
	Canny(grayMat, dstMat, 120, 150, 3);
	vector<Vec4i> lines;
	double rho = 1.0, theta = CV_PI / 180;
	int threshold = 30;
	HoughLinesP(dstMat, lines, rho, theta, threshold, 11, 10);
	for (size_t i = 0; i < lines.size(); i++)
	{
		Point pt1, pt2;
		pt1.x = lines[i][0]; 
		pt1.y = lines[i][1];
		pt2.x = lines[i][2];
		pt2.y = lines[i][3];
		line(srcMat, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	}
	imshow("dstMat", dstMat);
	imshow("srcMat", srcMat);
	waitKey(0);

}