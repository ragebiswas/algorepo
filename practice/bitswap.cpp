#include <iostream>
using namespace std;

bool getbit(int a, int i)
{
	return (a & (1 << i)) > 0;
}

void setbit(int& a, int i, bool val)
{
	if(val)
	{
		a |= (1 << i);
	}
	else
	{
		a &= ~(1 << i);
	}
}

int swapbits(int a, int i, int j)
{
	bool tmp = getbit(a, i);
	setbit(a, i, getbit(a, j));
	setbit(a, j, tmp);
	return a;
}


int main()
{
	cout<<swapbits(32, 5, 30)<<endl;
	cout<<swapbits(32, 30, 5)<<endl;
	cout<<swapbits(21, 1, 4)<<endl;
	cout<<swapbits(21, 4, 1)<<endl;
	return 0;
}
	