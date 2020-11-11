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
	vector<Vec2f> lines;
	double rho = 1.0, theta = CV_PI / 180;
	int threshold = 100;
	HoughLines(dstMat, lines, rho, theta, threshold);
//	HoughLines(grayMat, lines, 1.0, CV_PI / 180, 102, 0, 0, 0, 0.1);
	vector<Vec2f>::iterator it = lines.begin();
	//for (; it != lines.end(); ++it)
	//{
	//	float rho_1 = (*it)[0], theta_1 = (*it)[1];
	//	Point pt1, pt2;
	//	double a = cos(theta_1);
	//	double b = sin(theta_1);
	//	double x0 = a * rho_1;
	//	double y0 = b * rho_1;
	//	pt1.x = saturate_cast<int>(x0 + 1000 * (-b));
	//	pt1.y = saturate_cast<int>(y0 + 1000 * (a));
	//	pt2.x = saturate_cast<int>(x0 + 1000 * (-b));
	//	pt2.y = saturate_cast<int>(y0 + 1000 * (a));
	//	line(dstMat, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	//	cout << pt1.x << endl;
	//	cout << pt1.y << endl;
	//}
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 2000 * (-b));  //把浮点数转化成整数
		pt1.y = cvRound(y0 + 2000 * (a));
		pt2.x = cvRound(x0 - 2000 * (-b));
		pt2.y = cvRound(y0 - 2000 * (a));
		line(srcMat, pt1, pt2, Scalar(255), 1, CV_AA);
	}
//	imshow("dstMat", dstMat);
	imshow("srcMat", srcMat);
	waitKey(0);

}