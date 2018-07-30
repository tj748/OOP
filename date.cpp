#include "std_lib_facilities.h"
#include "date.h"

vector<string> month_names = { " ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
vector<int> last_days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<int> leap_last_days = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date() : y{ 2001 }, m{ Month::jan }, d{ 1 } {}

Date::Date(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd } {
	if (!isvalid()) {
		try {
			throw Invalid{};
		}
		catch(...) {
			cout << "You have an invalid input! Please input another date: ";
		}
	}
}

void Date::add_day(int n) {

	vector<int> days_in_use;
	if (leapyear(y)) {
		days_in_use = leap_last_days;
	}
	else {
		days_in_use = last_days;
	}
	if (n > days_in_use[int(m)]) {
		while (n > days_in_use[int(m)]) {
			int remaining = days_in_use[int(m)] - d;
			n -= remaining;
			d = 0;
			add_month(1);
		}
		d += n;
	}
	 
	else if (n <= days_in_use[int(m)]) {
		int days_left_in_month;
		days_left_in_month = days_in_use[int(m)] - d;
		if (days_left_in_month < n) {
			d = n - days_left_in_month;
			add_month(1);
		}
		else if (days_left_in_month >= n) {
			d += n;
		}
	}
}

void Date::add_month(int n) {
	for (int i = 0; i < n; i++) {
		int current_month = month();
		current_month = (current_month + 1) % 12;
		m = Month(current_month);
		if (m == Month::jan) {
			add_year(1);
		}
	}
}

void Date::add_year(int n) {
	y += n;
}

bool Date::isvalid() {
	if (int(m) < 1 || int(m) > 12) {
		return false;
	}

	else if (d < 1 || d > 31) {
		return false;
	}

	else if (d >= 1 || d <= 31) {
		switch (int(m)) {
			case '2' :
				if (d > 28) {
					return false;
				}
			case '4': case '6' : case '9' : case '11' :
				if (d > 30) {
					return false;
				}
			default:
				return true;
		}
	}

	else if (y < 1) {
		return false;
	}
}

bool leapyear(const int& y) {
	if (((y % 4) == 0) && ((y % 100) != 0) || (y % 400) == 0) {
		return true;
	}
	return false;
}

ostream& operator << (ostream& os, const Date& d) {
	//return os << '(' << d.year() << ',' << months[d.month()] << ',' << d.day() << ')';
	return os << month_names[d.month()] << " " << d.day() << ", " << d.year();
}

bool operator == (const Date& d1, const Date d2) {
	if (d1.year() == d2.year() && d1.month() == d2.month() && d1.day() == d2.day()) {
		return true;
	}
	return false;
}

bool operator != (const Date& d1, const Date d2) {
	return !(d1 == d2);
}

