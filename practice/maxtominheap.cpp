#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

template<class T>
void print(T val)
{
	cout<<val<<" ";
}

template<class T>
class MaxHeap
{
private:
    vector<T> heap;
    size_t sz;
    
    size_t parent(size_t i)
    {
		return i/2;
    }
    
    size_t left(size_t i)
    {
		return 2*i + 1;
    }
    
    size_t right(size_t i)
    {
		return 2*i + 2;
    }
    
    size_t size()
    {
		return sz;
    }
    
    void heapify(size_t i)
    {
		assert(i < size());
		
		T val = heap[i];
		T larger = val;
		size_t larger_idx = i;
		
		if(left(i) < size() && heap[left(i)] > heap[i])
		{
			larger = heap[left(i)];
			larger_idx = left(i);
		}
		
		if(right(i) < size() && heap[right(i)] > larger)
		{
			larger = heap[right(i)];
			larger_idx = right(i);
		}
		
		if(larger_idx != i)
		{
			swap(heap[i], heap[larger_idx]);
			heapify(larger_idx);
		}
	}
    
    void build()
    {
		int i = size()/2;
		while(i >= 0)
		{
			heapify(i--);
		}
    }
    
   
public:
    MaxHeap(vector<T> v)
    {
        heap = v;
        sz = v.size();
        build();
    }
    
    vector<T> sort()
    {
		int i = size() - 1;

		// note condition
		while(i >= 1)
		{
			swap(heap[0], heap[i--]);
			sz--;
			heapify(0);
		}
		return heap;
    }

    void print()
    {
		for(size_t i=0; i<sz; i++)
			cout<<heap[i]<<" ";
    }
};

int main()
{
	int arr[] = { -5, 3, 4, 9, 2, -4 };
	vector<int> v(arr, arr+6);
	
	MaxHeap<int> heap(v);
	cout<<"Heap: "; 
	heap.print();
	cout<<endl;
	
	vector<int> s = heap.sort();
	cout<<"Sorted: "; 
	for_each(s.begin(), s.end(), print<int>);
	cout<<endl;
	
	return 0;
}