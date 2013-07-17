#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void print(int i)
{
	cout<<i<<" ";
}

vector<vector<int> > waystosum(int target)
{
	vector<vector<int> > vv;
	if(target == 0)
	{		
		// base case - empty vector
		vector<int> v;
		vv.push_back(v);
		return vv;
	}
	
	for(int i=1; i<=target; i++)
	{
		vector<vector<int> > sub = waystosum(target - i);		
		
		for(size_t j=0; j<sub.size(); j++)
		{
			vector<int> vi(1, i);
			vector<int> tmp = sub[j];
			vi.insert(vi.end(), tmp.begin(), tmp.end());
			vv.push_back(vi);
		}
	}
	return vv;
}

int main()
{
	vector<vector<int> > res = waystosum(5);
	for(size_t i = 0; i < res.size(); i++)
	{
		for_each(res[i].begin(), res[i].end(), print);
		cout<<endl;
	}
	return 0;	
}
