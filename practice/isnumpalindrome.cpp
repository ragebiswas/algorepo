#include <iostream>
#include <cassert>

using namespace std;

bool getbit(int n, int i)
{
	return (n & (1 << i)) > 0;
}

bool setbit(int n, int i, bool val)
{
	if(val)
	{
		n |= (1 << i);
	}
	else
	{
		n &= ~(1 << i);
	}
}

bool ispalindrome(int n)
{
	int first = 31;
	while(first > 0)
	{
		if(getbit(n, first))
			break;
		first--;
	}
	
	assert(first > 0);
	int last = 0;
	
	bool ispalindrome = true;
	while(first > last)
	{
		if(getbit(n,first) != getbit(n, last))
		{
			ispalindrome = false;
			break;
		}
		first--;
		last++;
	}
	return ispalindrome;
}

int main()
{
	cout<<ispalindrome(5)<<endl;
	cout<<ispalindrome(32)<<endl;
	cout<<ispalindrome(42)<<endl;
	cout<<ispalindrome(85)<<endl;
	return 0;
}