// Tracy Joseph
// Assignment 5: Date Class

#include "std_lib_facilities.h"
#include "date.h"


int main() {

	
	cout << "Please enter a date in the format (YYYY,MM,DD): ";

	char paren1, paren2;
	int year, month, date;
	char com1, com2;

	cin >> paren1 >> year >> com1 >> month >> com2 >> date >> paren2;
	Date test(year, Month(month), date);
	
	if (test.isvalid()) {
		cout << "You entered: " << test << endl;
	}
	else {
		while (test.isvalid() == false) {
			cin >> paren1 >> year >> com1 >> month >> com2 >> date >> paren2;
			Date test(year, Month(month), date);
		}
		cout << "You entered: " << test << endl;
	}

	Date today(2018, Month::jul, 20);
	cout << "Our test date is " << today << endl;

	today.add_year(2);
	cout << "When we add 2 years to the date, we get " << today << endl;

	today.add_month(7);
	cout << "When we add 7 months to the date, we get " << today << endl;

	today.add_day(9);
	cout << "When we add 9 days to the date, we get " << today << endl;
	
	
	Date d1(2018, Month::jul, 20);
	cout << "Is " << today << " equal to " << d1 << ": " << (d1 == today) << endl;

	Date d2(2021, Month::mar, 1);
	cout << "Is " << today << " equal to " << d2 << ": " << (d2 == today) << endl;

	Date d3(2013, Month::nov, 16);
	cout << "Is " << today << " not equal to " << d3 << ": " << (d3 != today) << endl;

	Date d4(2021, Month::mar, 1);
	cout << "Is " << today << " not equal to " << d4 << ": " << (d4 != today) << endl;

	Date d5(2004, Month::feb, 18);
	cout << "Is " << d5 << " a leap year " << ": " << leapyear(d5.year()) << endl;

	Date d6(2007, Month::oct, 5);
	cout << "Is " << d6 << " a leap year " << ": " << leapyear(d6.year()) << endl;
	
	Date default_date;
	cout << "The default date is: " << default_date << endl;


}