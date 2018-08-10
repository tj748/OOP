// Tracy Joseph
// Assignment 6D: Implementing vectors


#define _SCL_SECURE_NO_WARNINGS

#include "std_lib_facilities.h"

class vect {

	int sz;
	double* elem;

public:
	vect(int s) : sz{ s }, elem{ new double[s] } { /* */ }

	vect(const vect& arg) : sz{ arg.sz }, elem{ new double[arg.sz] } {
		//allocate space, then initialize via copy
		
		copy(arg.elem, arg.elem + arg.sz, elem); // from std lib
	}

	vect& operator=(const vect& a) {
		// make this vector a copy of a

		double* p = new double[a.sz];

		copy(a.elem, a.elem + a.sz, p);
		delete[] elem;
		elem = p;
		sz = a.sz;
		return *this; // return self-ref
	}

	~vect() {
		delete[] elem;
	}
	/*
	double get(int i) {
		return elem[i];
	}
	void set(int i, double d) {
		elem[i] = d;
	}
	*/
	double& operator[](int n) {
		return elem[n];
	}

	double operator[](int n) const {
		return elem[n];
	}

};


void f(int n) {
	vect v(3);

	//v.set(2, 2.2);
	v[2] = 2.2;
	
	
	vect v2 = v;
	
	//v.set(1, 9.9);
	v[1] = 9.9;
	

	//v2.set(0, 8.8);
	v2[0] = 8.8;
	

	//cout << v.get(0) << ' ' << v2.get(1);
	cout << v[0] << ' ' << v2[1] << endl;
}

int main() {
	f(3);
	return 0;
}