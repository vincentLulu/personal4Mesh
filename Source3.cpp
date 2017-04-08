#include <iostream>
#include <fstream>

#include "Readin.h"
#include "Method3.h"
#include "Export.h"

using namespace std;
using namespace Eigen;

int main() {
	/***** Common functions tests *****/
	Common DataBase;
	vector <Common> PointCloud;
	const string file("normal-ct-brain");
	string filename;
	for (int i = 0; i < 1; ++i) {
		filename = file + " " + to_string(i) +".jpg";
		DataBase.Read_Process(filename, PointCloud);
	}
	cout << "Total Nodes: " << PointCloud.size() << endl;
	//Export(PointCloud);
	
 }