/*
ID: rajorsh2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
#define LEN 1000000

static string readline(ifstream& ifs)
{
	char line[LEN];
	ifs.getline(line, LEN);
	string s = line;
	return s;
}

static string int_to_string(long i)
{
	ostringstream oss;
	oss<<i;
	return oss.str();
}

static long string_to_int(string s)
{
	istringstream iss(s);
	int i;
	iss>>i;
	return i;
}

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    
    a = readline(fin);
    b = readline(fin);
    
    int m1 = 1;
    int m2 = 1;
    
    for(int i=0; i<a.size(); i++) m1 = (m1 * (a[i]-'A'+1)) % 47;
    for(int i=0; i<b.size(); i++) m2 = (m2 * (b[i]-'A'+1)) % 47;
    
    if(m1 == m2)
        fout <<"GO\n";
    else
        fout << "STAY\n";
    
    return 0;
}