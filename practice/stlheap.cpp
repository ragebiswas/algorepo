#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

template<class T>
void print(T val)
{
	cout<<val<<" ";
}

int main()
{
	int arr[] = { 3, 2, 1, 5, 6, 7, 4 };
	vector<int> v(arr, arr+7);
	
	vector<int> v1 = v;
	make_heap(v1.begin(), v1.end());
	cout<<"Max heap: ";
	while(!v1.empty())
	{
		cout<<v1.front()<<" ";
		pop_heap(v1.begin(), v1.end());
		v1.pop_back();
	}
	
	vector<int> v2 = v;
	make_heap(v2.begin(), v2.end(), greater<int>());
	cout<<"\nMin heap: ";
	while(!v2.empty())
	{
		cout<<v2.front()<<" ";
		pop_heap(v2.begin(), v2.end(), greater<int>());
		v2.pop_back();
	}	
	
	vector<int> v3 = v;
	priority_queue<int> p1(v3.begin(), v3.end());
	cout<<"\n\nMax Priority Queue: ";
	while(!p1.empty())
	{
		cout<<p1.top()<<" ";
		p1.pop();
	}
	
	vector<int> v4 = v;
	priority_queue<int, vector<int>, greater<int> > p2(v4.begin(), v4.end());
	cout<<"\nMin Priority Queue: ";
	while(!p2.empty())
	{
		cout<<p2.top()<<" ";
		p2.pop();
	}
	
	
	
	return 0;
}