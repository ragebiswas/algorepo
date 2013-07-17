#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void reversewords(string& input)
{
	size_t sz = input.size();

	// reverse the whole string
	for(size_t i = 0; i < sz/2; i++)
input[i] = input[sz-i-1];

// reverse each word
bool inword = false;
size_t startpos = 0;
size_t endpos = 0;

for(size_t i = 0; i < sz; i++)
{
	if(!isspace(input[i]) && !inword)
		startpos = i;
	
if(isspace(input[i]))
{
	if(inword)
	{
		endpos = i;
		while(startpos < endpos)
		{
			swap(input[startpos++], input[endpos--]);
		}
	}
	inword = false;
}
}
}

int main()
{
	string s = "hello this is a sentence";
	reversewords(s);
	cout<<s<<endl;
	return 0;
}