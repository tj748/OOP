// Tracy Joseph
// Assignment 8: Customizing the Calculator

// I have chosen to add finding the nth root of a number to my calulator (i.e. 5_32 would return 2)
// I have also chosen to add bitwise operations
	// (bit and) & copies a bit to the result if it exists in both operands.
	// (bit or) | copies a bit if it exists in either operand.
	// (bit left shift) < left operands value is moved left by the number of bits specified by the right operand.
	// (bit right shift) >  left operands value is moved right by the number of bits specified by the right operand. 

#include "std_lib_facilities.h"
#include "custom_tokens.h"
#include "custom_vars.h"

double statement(Token_stream& ts);
double expression(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);
double exponent(Token_stream& ts);


double statement(Token_stream& ts) {

	Token t = ts.get();
	if (t.kind == name) {
		Token var = t;
		//        cout << "Got a var with name " << var.name << endl;
		t = ts.get();
		if (t.kind == '=') {
			double d = expression(ts);
			set_value(var.name, d);
			return d;
		}
		else if (t.kind == print) {
			ts.putback(t);
			return get_value(var.name);
		}
		ts.putback(t);
		ts.putback(var);
		return expression(ts);
	}
	ts.putback(t);
	return expression(ts);
}

double expression(Token_stream& ts) {

	double left = term(ts);
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+': {
			left += term(ts);
			t = ts.get();
			break;
		}

		case '-': {
			left -= term(ts);
			t = ts.get();
			break;
		}

		default:
			ts.putback(t);
			return left;
		}
	}
}

double term(Token_stream& ts) {

	double left = exponent(ts);
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '*': {
			left *= exponent(ts);
			t = ts.get();
			break;
		}

		case '/': {
			double d = exponent(ts);
			if (d == 0) {
				error("Impossible to divide by 0");
			}
			left /= d;
			t = ts.get();
			break;
		}

		case '%': {
			double d = exponent(ts);
			if (d == 0) {
				error("Impossible to divide by 0");
			}
			left = fmod(left, d);
			t = ts.get();
			break;
		}

		default:
			ts.putback(t);
			return left;
		}
	}

}

double primary(Token_stream& ts) {
	Token t = ts.get();

	switch (t.kind) {

		case number: 
			return t.value;

		case '(': {
			double d = expression(ts);
			t = ts.get();
			return d;
		}

		case name: {
			Token next_t = ts.get();
			if (next_t.kind == '(') {
				double d = expression(ts);
				t = ts.get();
				if (t.kind != ')') {
					error("')' expected");
				}
				return d;
			}
			else {
				ts.putback(next_t);
				return get_value(t.name);
			}
		}

		case '-':
			return -primary(ts);

		case '+':
			return primary(ts);

		default:
			error("You have an error: primary was expected");

	}
	return t.value;
}

double exponent(Token_stream& ts) {
	double left = primary(ts);
	Token t = ts.get();

	if (t.kind == power) {
		double d = primary(ts);
		return pow(left, d);
	}

	else if (t.kind == root_num) {
		double d = primary(ts);
		return pow(d, (1/left));
	}

	else if (t.kind == binary_and) {
		double d = primary(ts);
		unsigned int a = d;
		unsigned int b = left;
		unsigned int c = 0;

		c = a & b;
		return c;
	}

	else if (t.kind == binary_or) {
		double d = primary(ts);
		unsigned int a = d;
		unsigned int b = left;
		unsigned int c = 0;

		c = a | b;
		return c;
	}

	else if (t.kind == binary_left_shift) {
		double d = primary(ts);
		unsigned int a = d;
		unsigned int b = left;
		unsigned int c = 0;

		c = b << a;
		return c;
	}

	else if (t.kind == binary_right_shift) {
		double d = primary(ts);
		unsigned int a = d;
		unsigned int b = left;
		unsigned int c = 0;

		c = b >> a;
		return c;
	}

	else {
		ts.putback(t);
		return left;
	}

}


void clean_up_mess(Token_stream& ts) {
	ts.ignore(print);
}

void calculate(Token_stream& ts) {
	while (cin) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) {
				t = ts.get();
			}
			if (t.kind == quit) {
				return;
			}
			ts.putback(t);
			cout << result << setprecision(10) << statement(ts)  << endl;
		}
		catch (exception& e) {
			cerr << e.what() << '\n';
			clean_up_mess(ts);
		}
	}

}

int main() {
	
	Token_stream ts;
	
	try {
		calculate(ts);
		return 0;
	}

	catch (exception& e) {
		cerr << e.what() << '\n';
		return 1;
	}
	
	
}



