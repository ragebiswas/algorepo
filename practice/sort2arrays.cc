#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int i)
{
  cout<<i<<" ";
}


int get(int index, vector<int>& v1, vector<int>& v2)
{
  if(index < v1.size())
    return v1[index];
  else
    return v2[index-v1.size()];
}


void set(int index, int val, vector<int>& v1, vector<int>& v2)
{
  if(index < v1.size())
    v1[index] = val;
  else
    v2[index-v1.size()] = val;
}

void sort2arrays(vector<int>& v1, vector<int>& v2)
{
  size_t sz = v1.size() + v2.size();

  // basic selection sort algo
  for(size_t i=0; i < sz - 1; i++)
  {
    int min = get(i + 1, v1, v2);
    int minindex = i + 1;

    for(size_t j=i; j < sz; ++j)
    {
      if(get(j, v1, v2) < min)
      {
        min = get(j, v1, v2);
        minindex = j;
      }
    }

    // swap
    int temp = get(i, v1, v2);
    set(i, min, v1, v2);
    set(minindex, temp, v1, v2);
  }

}

int main()
{
  int a1[] = { 11, 4, 7, 3};
  vector<int> v1(a1, a1+4);

  int a2[] = { 5, 1, 33 };
  vector<int> v2(a2, a2+3);

  sort2arrays(v1, v2);

  cout<<"Array 1: ";
  for_each(v1.begin(), v1.end(), print);
  cout<<endl;

  cout<<"Array 2: ";
  for_each(v2.begin(), v2.end(), print);
  cout<<endl;

}
