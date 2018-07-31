// Tracy Joseph
// Assignment 6B: Pointers and Sizes of Variables

#include "std_lib_facilities.h"

int main() {

	char c = 'a';
	int i = 4092;
	double d = 3.14;
	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	cout << "cp = " << cp << " and it's value is " << *cp << endl;
	cout << "The size of cp is " << sizeof(cp) << endl;
	cout << "The size of c is " << sizeof(c) << '\n' << endl;

	cout << "ip = " << ip << " and it's value is " << *ip << endl;
	cout << "The size of ip is " << sizeof(ip) << endl;
	cout << "The size of i is " << sizeof(i) << '\n' << endl;

	cout << "dp = " << dp << " and it's value is " << *dp << endl;
	cout << "The size of dp is " << sizeof(dp) << endl;
	cout << "The size of d is " << sizeof(d) << '\n' << endl;

}
