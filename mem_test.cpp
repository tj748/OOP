// Tracy Joseph
// Assignment 6C: Memory Leaks and Stack Overflow

#include "std_lib_facilities.h"

int main() {

	int i = 0;
	while (true) {
		double* dptr = new double[10000];
		cout << "Loop " << i << endl;
		cout << "dptr[0] = " << dptr[0] << endl;
		i++;
	}
}