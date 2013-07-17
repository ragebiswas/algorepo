#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int main()
{
	int ncases;
	cin>>ncases;

	string map, input;
	cin>>map;

	assert(map.size() == 26);

	while(ncases--)
	{
		cin>>input;
		for(int i=0; i<input.size(); ++i)
		{
			char c = input[i];
			if(c == '_') 
				cout<<" ";			
			else if(isalpha(c)) 
			{
				char o;
				if(isupper(c))
					o = toupper(map[tolower(c)-'a']);
				else 
					o = map[c-'a'];
				cout<<o;
			}
			else
				cout<<c;
		}
		cout<<endl;
	}

	return 0;
}