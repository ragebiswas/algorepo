#include <iostream>
#include <string>
using namespace std;

string removeoccurrence(string input, string key)
{
	size_t pos = 0;	
	
	for(size_t i=0; i<input.size(); i++)
	{
		if(input[i] == key[0])
		{
			bool match = true;
			for(size_t j=1; j<key.size(); j++)
			{
				if(input[i+j] != key[j])
					match = false;
			}			
			if(match)
			{
				i += key.size()-1;
				continue;
			}
		}
		input[pos++] = input[i];
	}
	
	input.erase(pos);
	return input;
}

int main()
{
	string s = "abcdabchelloabcolababbcabcdooabc";
	cout<<removeoccurrence(s, "abc")<<endl;
	return 0;
}