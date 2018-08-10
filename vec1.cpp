// Tracy Joseph
// Assignment 6D: Implementing vectors

#include "std_lib_facilities.h"

class vect {

	int sz;
	double* elem;

public:
	vect(int s) : sz{ s }, elem{ new double [s] } { /* */}

	~vect() {
		delete elem;
	}
	
	double get(int i) {
		return elem[i];
	}
	void set(int i, double d) {
		elem[i] = d;
	}
};

void f(int n) {
	vect v(3);
	v.set(2, 2.2);
	vect v2 = v;
	v.set(1, 9.9);
	v2.set(0, 8.8);
	cout << v.get(0) << ' ' << v2.get(1);
}

int main() {
	while (true) {
		f(10);
	}
}