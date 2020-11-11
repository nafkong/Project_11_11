#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("source.png", 1);
	Mat dstMat;
	if (srcMat.empty())
		return -1;
	Point2f center(srcMat.cols / 2.0, srcMat.rows / 2.0);
	Mat rot = getRotationMatrix2D(center, -10, 1);
	Rect bbox = RotatedRect(center, srcMat.size(), -10).boundingRect();
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	warpAffine(srcMat, dstMat, rot, bbox.size(),1);
	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);
}