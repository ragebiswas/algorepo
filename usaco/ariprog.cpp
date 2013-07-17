/*
ID: rajorsh2
PROG: ariprog
LANG: C++
*/
#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int n, m;
int bsq[251*251*2];
vector<int> nums;
int largest = 0;

void init()
{
	for(int p=0; p<=m; p++)
	{
		for(int q=0; q<=m; q++)
		{
			int sq = p*p + q*q;
			if(bsq[sq] == 0)
			{
				bsq[sq] = 1;
				nums.push_back(sq);
			}
		}
	}
	sort(nums.begin(), nums.end());
	largest = nums[nums.size()-1];
}


int main() 
{
	ifstream cin("ariprog.in");
    ofstream cout("ariprog.out");
	cin>>n>>m;

	init();

    bool found = false;
	for(int delta = 1; delta < largest; delta++)
	{
		for(int i = 0; i < nums.size(); i++)
		{
			int start = nums[i];
			int end = start + (n-1)*delta;

			if(end > largest)
				break;

			if(bsq[end] != 0)
			{
				bool possible = true;
				for(int k = start + delta; k <= end; k += delta)
				{
					if(bsq[k] == 0)
					{
						possible = false;
						break;
					}
				}

				if(possible) 
				{
                    found = true;
					cout<<start<<" "<<delta<<endl;
				}
			}
		}
	}
    
    if(!found)
        cout<<"NONE\n";

	return 0;
}