#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() 
{
	int ncases;
	cin>>ncases;
	string line;
	getline(cin, line);

	while(ncases--)
	{
		getline(cin, line);
		vector<int> chars(26, 0);
		transform(line.begin(), line.end(), line.begin(), ::toupper);
		for(int i=0; i<line.size(); i++)
		{
			if(isalpha(line[i])) 
				chars[line[i]-'A'] = 1;
		}
		int t = accumulate(chars.begin(), chars.end(), 0);
		if(t == 26)
		{
			cout<<"~"<<endl;
		}
		else
		{
			for(int i=0; i<26; i++)
			{
				if(chars[i] == 0)
				{
					cout<<(char)(i+'A')<<endl;
					break;
				}
			}
		}
	}

	return 0;
}