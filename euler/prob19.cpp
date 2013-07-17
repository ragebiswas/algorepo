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
	int finalyr = 2000;

	int daysnonleap[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysleap[] =    { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int *daysptr = NULL;

	// 0 - monday, 1 - tuesday, ... 6 - sunday
	int startday = 1; // will be 1 for 1901
	int startyr = 1901;

	vector<int> firsts(7,0);

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
			if(curdate==1)
			{
				firsts[curday]++;
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
	
	vector<int> &t = firsts;
	cout<<t[6]<<endl;

	return 0;
}