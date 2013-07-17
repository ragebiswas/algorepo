#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

inline void printreverse(char *str, int idx)
{
	for(int i = idx; i >= 0; i--)
		cout<<str[i];
}

int main(int argc, char** argv)
{
	string line;
	char word[BUFSIZ];
	ifstream fin(argv[1]);
	
	while(getline(fin, line))
	{
		const char* l = line.c_str();
		int len = 0, inword = 0;
		for(size_t i=0; i<line.size(); ++i)
		{
			if(isalnum(l[i]))
			{
				inword = 1;
				word[len++] = l[i];
			}
			else
			{
				if(inword)
				{
					inword = false;
					printreverse(word, len-1);
					len = 0;					
				}
				cout<<l[i];				
			}
		}        
   		if(inword)
		{
			inword = false;
			printreverse(word, len-1);
			len = 0;					
		}
		cout<<"\n";
	}
	return 0;
}