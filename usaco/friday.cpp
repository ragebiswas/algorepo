/*
ID: rajorsh2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

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


static bool isleap(int y)
{
	return ((y%100==0 && y%400==0) || (y%100!=0 && y%4==0));
}

int main()
{
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");

	int N = string_to_int(readline(fin));
	int finalyr = 1900+N-1;

	int daysnonleap[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysleap[] =    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int *daysptr = NULL;

	// 0 - monday, 1 - tuesday, ... 6 - sunday
	int startday = 0; // will be 0 for 1900
	int startyr = 1900;

	vector<int> thirteens(7,0);

	for(int yr = startyr; yr <= finalyr; yr++)
	{
		// process this year
		int curmonth = 0;
		int curdate = 1;
		int curday = startday; 
		int numdays = isleap(yr) ? 366: 365;
		daysptr = isleap(yr) ? daysleap : daysnonleap;

		for(int d=1; d<=numdays; d++)
		{
			if(curdate==13)
			{
				thirteens[curday]++;
			}

			if(curdate+1 > *(daysptr+curmonth))
			{
				curdate = 1;
				curmonth++;
			}
			else
			{
				curdate++;
			}
			curday = (curday+1)%7;
		}

		// post processing
		startday = (startday+1)%7;
		if(isleap(yr))
			startday = (startday+1)%7;
	}
	
	vector<int> &t = thirteens;
	fout<<t[5]<<" "<<t[6]<<" "<<t[0]<<" "<<t[1]<<" "<<t[2]<<" "<<t[3]<<" "<<t[4]<<endl;

	return 0;
}