// Assignment 8

const char invalid = 'i';
const char name = 'x';

const char number = '8';
const char quit = 'q';
const char print = ';';
const char power = '^';

const char root_num = '_';

const char binary_or = '|';
const char binary_and = '&';
const char binary_left_shift = '<';
const char binary_right_shift = '>';

const string prompt = "> ";
const string result = "= ";


class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch) : kind{ ch } {}
	Token(char ch, double val) : kind{ ch }, value{ val } {}
	Token(char ch, string n) : kind{ ch }, name{ n } {}
};

class Token_stream {
public:
	Token get();
	void putback(Token t);
	Token popback();
	void ignore(char c);

private:
	vector<Token> buffer;
};