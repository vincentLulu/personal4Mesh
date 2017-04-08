#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Readin.h"
#include "Method3.h"

Common::Common() {
}

Common::~Common() {
}

void Common::Read_Process(string file, vector<Common> &target) {
	double queue;
	if (file.size() > 4) {
		queue = stod(file.substr(file.size() - 5, 2));
	}
	cout << "reading in " << file << endl;
	cv::Mat img = cv::imread(file);
	cv::cvtColor(img, img, CV_RGB2GRAY);
	if (img.empty()) {
		cout << "error in loading picture!" << endl;
		throw invalid_argument("received negative value");
	}
	cv::namedWindow("hah");
	cv::imshow("hah", img);
	cv::waitKey(600);
	cv::destroyWindow("hah");

	Eigen::Vector3d tempVector;
	int row = img.rows;
	int col = img.cols;
	Common tempCommon;
	cv::Scalar intensity;
	bool lag = false;
	ofstream out("OutMethod3.obj");
	for (int x = 0; x < row; ++x) {
		for (int y = 0; y < col; ++y) {
			intensity = img.at<uchar>(x, y);
			tempVector << double(x), double(y), queue;
			tempCommon.Assign_cords(tempVector);
			tempCommon.Assign_scale(1);
			tempCommon.Assign_CVScalar(intensity);
			tempCommon.Assign_Normal();
				
			target.push_back(tempCommon);
			
			if (check_cube(row, col, tempCommon, target)) { // any node in cubic element satisfy condition

			}
		}
	}
}


Eigen::Vector3d Common::Get_Cords() {
	return cords;
}
double Common::Get_Scale() {
	return scale;
}
cv::Scalar Common::Get_CVScalar() {
	return intensity;
}
Eigen::Vector3d Common::Get_Normal() {
	return normal;
}


void Common::Assign_cords(Eigen::Vector3d value) {
	cords = value;
}
void Common::Assign_scale(double value) {
	scale = value;
}
void  Common::Assign_CVScalar(cv::Scalar value) {
	intensity = value;
}
void Common::Assign_Normal() {
	Eigen::Vector3d temp(0, 0, 0);
	normal = temp;
}
void Common::Modify_Normal(Eigen::Vector3d value) {
	normal += value;
}