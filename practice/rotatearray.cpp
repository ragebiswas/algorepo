#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<int> > rotate(vector<vector<int> > arr)
{
	int R = arr[0].size();
	int C = arr.size();
	vector<int> v(C, 0);
	vector<vector<int> > res(R, v);
	
	for(size_t r=0; r < arr.size(); r++)
		for(size_t c=0; c < arr[0].size(); c++)
			res[c][C-1-r] = arr[r][c];
	
	return res;
}

void print(vector<vector<int> > res)
{
	for(size_t i=0; i<res.size(); i++)
	{
		for(size_t j=0; j<res[i].size(); j++)
		{
			cout<<setw(3)<<res[i][j]<<" ";
		}
		cout<<'\n';
	}
}


int main()
{
	vector<vector<int> > input;
	int e = 1;
	size_t r = 10, c = 15;
	
	for(size_t i=0; i<r; i++)
	{
		vector<int> v;
		for(size_t j=0; j<c; j++)
			v.push_back(e++);
		input.push_back(v);
	}
	
	cout<<"Input:\n";
	print(input);	
	vector<vector<int> > res = rotate(input);
	
	cout<<"\nOutput:\n";
	print(res);

	return 0;
}
	