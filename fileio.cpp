// Tracy Joseph
// Assignment 6: File I/O

#include "std_lib_facilities.h"

int main() {

	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };
	if (!ist) {
		error("can't open input file ", iname);
	}
	
	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname };
	if (!ost) {
		error("can't open output file ", oname);
	}
	
	int hour;
	char sep1;
	double temp;
	char sep2;
	double pressure;

	while (ist >> hour >> sep1 >> temp >> sep2 >> pressure) {
		//cout << hour << '\t' << temp << '\t' << pressure << endl;
		ost << hour << '\t' << temp << '\t' << pressure << endl;
	}

}