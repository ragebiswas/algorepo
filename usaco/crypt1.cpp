/*
ID: rajorsh2
PROG: crypt1
LANG: C++
*/

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

inline bool possible(int num, vector<bool>& digits)
{
	while(num)
	{
		if(digits[num%10] == false)
			return false;
		num /= 10;
	}
	return true;
}

int main()
{
	ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    
	int n, t;
	vector<bool> digits(10, false);
	fin>>n;

	while(n--)
	{
		fin>>t;
		digits[t] = true;
	}

	// multiplicand, multiplier
	int nc = 0; 

	for(int mand=111; mand <= 999; mand++)
	{
		for(int mier=11; mier <= 99; mier++)
		{
			// check if mand * mier is a possibility
			if(possible(mand, digits) && possible(mier, digits))
			{
				int miertmp = mier;
				bool poss = true;

				while(miertmp)
				{
                    int tmp = mand * (miertmp%10);
                    
                    if(tmp < 111 || tmp > 999)
                    {
                        poss = false; 
                        break;
                    }
					if(!possible(tmp, digits))
					{
						poss = false;
						break;
					}
					miertmp /= 10;
				}

				if(!possible(mand*mier, digits))
					continue;

				if(mand*mier > 9999 || mand*mier < 1111)
					continue;

				if(poss)
				{
					//fout<<"mand="<<mand<<" mier="<<mier<<endl;
					nc++;
				}
			}
		}
	}
    
    fout<<nc<<endl;
    return 0;
}