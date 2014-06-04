// Artificial Intelligence (Level 1)
// String manipulation
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

double I, U, P;


double getDouble(const string& val) 
{
	double d;
	istringstream iss(val);
	iss >> d;
	char last = val[val.size() - 1];
	if (last == 'k') {
		d = d*1000;
	}
	else if(last == 'M') {
		d = d*1000000;
	}
	else if(last == 'm') {
		d = d/1000;
	}
	return d;
}

void getValue(const string& token)
{
	int last = token.size() - 1;
	while (!isalpha(token[last]) && last > 2) {
		last--;
	}
	if (token[0] == 'I' && token[1] == '=' && token[last] == 'A') {
		I = getDouble(token.substr(2, last - 2));
	}
	if (token[0] == 'U' && token[1] == '=' && token[last] == 'V') {
		U = getDouble(token.substr(2, last - 2));
	}
	if (token[0] == 'P' && token[1] == '=' && token[last] == 'W') {
		P = getDouble(token.substr(2, last - 2));
	}
}

int main()
{
	int nc;
	string line;
	cin >> nc;
	cin.ignore(1000, '\n');
	for (int c = 1; c <= nc; c++) {
		getline(cin, line);
		string tok;
		istringstream ss(line);
		I = -1.0, U = -1.0, P = -1.0;
		while (ss >> tok) {
			getValue(tok);
		}
		cout << "Problem #" << c << endl;
		if(I < 0) {
			cout << "I=" << fixed << setprecision(2) << P/U << "A" << endl;
		}
		else if (U < 0) {
			cout << "U=" << fixed << setprecision(2) << P/I << "V" << endl;			
		}
		else if(P < 0) {
			cout << "P=" << fixed << setprecision(2) << U*I << "W" << endl;
		}
		cout << endl;
	}
	return 0;
}