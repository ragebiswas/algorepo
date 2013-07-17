#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

class StackWithInt
{
private:
	int _var;
	
public:
	StackWithInt()
	{
		_var = 1;
	}
	
	bool empty()
	{
		return (_var == 1);
	}
	
	void push(const int val)
	{
		_var = _var * 10 + val;
	}
	
	int pop()
	{	
		assert(!empty());
		int ret = _var % 10;
		_var /= 10;
		return ret;
	}
	
};


int main()
{
	StackWithInt st;
	st.push(0);
	st.push(2);
	st.push(9);
	st.push(0);
	
	while(!st.empty())
	{
		cout<<"Pop first set: "<<st.pop()<<endl;
	}

	st.push(5);
	st.push(6);
	st.push(0);		
	
	while(!st.empty())
	{
		cout<<"Pop second set: "<<st.pop()<<endl;
	}
	
	return 0;
}