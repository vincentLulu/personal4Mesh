#ifndef  READIN
#define READIN
#include <Eigen\Dense>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <vector>

using namespace std;
using namespace Eigen;

struct Common {
	Common();
	~Common();
	void Read_Process(const string file, vector <Common> &target);
	Eigen::Vector3d Get_Cords();
	double Get_Scale();
	cv::Scalar Get_CVScalar();
	Eigen::Vector3d Get_Normal();
	void IdentifyNormal(Eigen::Vector3d vector) {
		Modify_Normal(vector);
	}
	
protected:
	void Assign_cords(Eigen::Vector3d value);
	void Assign_scale(double value);
	void Assign_CVScalar(cv::Scalar value);
	void Assign_Normal();
	void Modify_Normal(Eigen::Vector3d value);

	Eigen::Vector3d cords;
	double scale;
	Eigen::Vector3d normal;
	cv::Scalar intensity;
};
#endif // ! READIN



#pragma once
