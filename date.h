
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
	class Invalid {};
	Date();
	Date(int yy, Month mm, int dd);
	
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

	int month() const { return int(m); }
	int year() const { return y; }
	int day() const { return d; }
	bool isvalid();
	
private:
	int y, d;
	Month m;

};

ostream& operator << (ostream& os, const Date& d);

bool operator == (const Date& d1, const Date d2);

bool operator != (const Date& d1, const Date d2);

bool leapyear(const int& y);