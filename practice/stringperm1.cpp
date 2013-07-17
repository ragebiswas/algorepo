#include <iostream>
#include <string>
#include <vector>

using namespace std;

void stringperm1(string orig, string s, int index, vector<bool>& used)
{
	if(index >= s.size())
		cout<<s<<endl;
		
	for(int i=0; i<orig.size(); i++)
	{
		if(!used[i])
		{
			used[i] = true;
			s[index] = orig[i];
			stringperm1(orig, s, index+1, used);
			used[i] = false;
		}
	}
}

int main()
{
	string s = "abc";
	vector<bool> used(s.size(), false);
	stringperm1(s, s, 0, used);
	return 0;
}