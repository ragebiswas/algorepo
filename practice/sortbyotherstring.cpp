#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

void print(string s)
{
	cout<<s<<" ";
}

static string order;

int comp(char c1, char c2)
{
	if(order.find(c1) == string::npos)
		return false;
		
	if(order.find(c2) == string::npos)	
		return true;
	
	return order.find(c1) < order.find(c2);
}



string mysort(string input, string o)
{
	order = o;
	std::sort(input.begin(), input.end(), comp);
	return input;
}

int main()
{	
	string res = mysort("dabcdbcbbbcbabdcca", "cba");
	cout<<res<<endl;
	return 0;
}
