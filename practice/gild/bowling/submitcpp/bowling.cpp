#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;
#define SZ 100

int main(int argc, char** argv)
{
	enum { NORMAL, STRIKE, SPARE, EXTRA };
	string line, token;
	ifstream infile(argv[1]);	

	while(getline(infile, line))
	{
		int total = 0, i = 0, f = 0;
		int scores[30] = { 0 }, info[30] = { NORMAL };
		bool frameover= true;

		istringstream iss(line);
		while(iss>>token)
		{
			if(token[0] == 'X')
			{
				scores[i] = 10;
				total += 10;
				info[i] = STRIKE;
				f++;
				frameover = true;
			}
			else if(token[0] == '/')
			{
				scores[i] = 10 - scores[i-1];
				total += scores[i];
				info[i] = SPARE;
				f++;
				frameover = true;
			}
			else
			{
				scores[i] = atoi(token.c_str());
				total += scores[i];
				info[i] = NORMAL;
				if(frameover)
				{
					frameover = false;
				}
				else
				{
					frameover = true;
					f++;
				}
			}

			if(f > 10 || (f == 10 && !frameover))
			{
				info[i] = EXTRA;
				total -= scores[i];
			}


			if(i >= 1 && info[i-1] == SPARE)
			{
				scores[i-1] += scores[i];
				total += scores[i];
			}

			if(i >= 2 && info[i-2] == STRIKE)
			{
				scores[i-2] += (scores[i] + scores[i-1]);
				total += (scores[i] + scores[i-1]);
			}

			i++;
		}

		printf("%d\n", total);
	}

}