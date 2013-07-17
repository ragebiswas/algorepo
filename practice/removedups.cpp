#include <iostream>
#include <string>
using namespace std;

string removedups(string s)
{
	if(s.size() < 2)
		return s;
		
	int j, wpos = 1;
	for(int i = 1; i < s.size(); i++)
	{
		for(j = 0; j < wpos; j++)
		{
			if(s[j] == s[i])
				break;
		}
		
		if(s[j] != s[i])
		{
			s[wpos++] = s[i];
		}
	}	
	
	s.resize(wpos);
	return s;
}


int main()
{
	cout<<removedups("aabaaaabaaa")<<endl;
	cout<<removedups("abaaaabbbcccccccccdccccccccedaxu");
	return 0;	
}