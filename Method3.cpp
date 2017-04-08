#include "Method3.h"
#include <fstream>

bool check_cube(const int row, const int col, Common tempCommon, vector <Common> target) {
	if (tempCommon.Get_CVScalar().val[0] > 250) {
		return true;
	}
	else {
		int x = int(tempCommon.Get_Cords()[0]);
		int y = int(tempCommon.Get_Cords()[1]);
		int z = int(tempCommon.Get_Cords()[2]);

		int index0 = row*col*z + col*y + x -1;
		int index1 = row*col*z + col*(y - 1) + x;
		int index2 = index1 - 1;
		int index3 = row*col*(z - 1) + col*y + x;
		int index4 = index3 - 1;
		int index5 = row*col*(z - 1) + col*(y-1) + x;
		int index6 = index5 - 1;
		if (target[index0].Get_CVScalar().val[0] > 250 || target[index1].Get_CVScalar().val[0] > 250 ||
			target[index2].Get_CVScalar().val[0] > 250 || target[index3].Get_CVScalar().val[0] > 250 ||
			target[index4].Get_CVScalar().val[0] > 250 || target[index5].Get_CVScalar().val[0] > 250 ||
			target[index6].Get_CVScalar().val[0] > 250) {
			return true;
		}
		else {
			return false;
		}
	}
}

void check_out(const int row, const int col, Common tempCommon, const vector <Common> target, ofstream out) {
	if (tempCommon.Get_CVScalar().val[0] > 250) { // standard start point 
		out << "v " << tempCommon.Get_Cords()[0] << " " << tempCommon.Get_Cords()[1] << " " << tempCommon.Get_Cords()[2] << "\n";

	}
	else{ // start from previous point

	}
}