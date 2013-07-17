#include <iostream>
#include <queue>
using namespace std;

template<class T>
class StackWithQueue
{
private:
	queue<T> _pushq, _popq;

public:
	void push(const T& val)
	{
		_pushq.push(val);
	}

	T pop()
	{
		size_t sz = _pushq.size() - 1;
		while(sz--)
		{
			_popq.push(_pushq.front());
			_pushq.pop();
		}
		T val = _pushq.front();
		_pushq.pop();
		swap(_popq, _pushq);
		return val;
	}

	bool empty()
	{
		return _pushq.empty();
	}
};


int main()
{
	StackWithQueue<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
    st.push(5);

	while(!st.empty())
		cout<<st.pop()<<endl;

	return 0;
}	
