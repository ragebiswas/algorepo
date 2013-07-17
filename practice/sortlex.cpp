#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print(string s)
{
	cout<<s<<" ";
}

int comp(string s1, string s2)
{
	string first = s1 + s2;
	string second = s2 + s1;
	if(first > second)
		return true;
	else 
		return false;
}


void sort(vector<string>& v)
{
	std::sort(v.begin(), v.end(), comp);
}

int main()
{
	string arr[] = { "1", "54", "544", "9", "7", "944" };
	vector<string> vs(arr, arr+6);
	sort(vs);
	for_each(vs.begin(), vs.end(), print);
	return 0;
}
